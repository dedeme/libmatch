// Copyright 23-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "dmc/match.h"
#include "dmc/Iarr.h"

MatchSession *match_session (int double_round, int nplayers) {
  if (nplayers < 2)
    EXC_ILLEGAL_ARGUMENT("nplayers", "> 1", str_f("%d", nplayers))

  // Regularize players
  int is_odd = nplayers % 2;
  int np = nplayers + is_odd;
  int np1 = np - 1;
  int np_mid = np / 2;

  Iarr *players = iarr_new();
  RANGE0(i, nplayers) {
    iarr_push(players, i);
  }_RANGE
  if (is_odd) iarr_push(players, -1);

  MatchSession *session = matchSession_new();

  REPEAT(np1) {
    MatchRound *round = matchRound_new();

    int *pup = iarr_start(players);
    int *pdown = pup + np1;
    REPEAT(np_mid) {
      arr_push(matchRound_matches(round), matchPlayers_new(*pup++, *pdown--));
    }_RANGE
    arr_push(matchSession_rounds(session), round);

    // Rotate players
    int *ppys = iarr_start(players) + np1;
    int tmp = *ppys;
    int *ppys_end = iarr_start(players) + 1;
    while (ppys > ppys_end) {
      *ppys = *(ppys - 1);
      --ppys;
    }
    *ppys = tmp;
  }_REPEAT

  // Duplicate rounds if double session
  if (double_round) {
    arr_insert_arr(
      matchSession_rounds(session),
      np1,
      arr_map(matchSession_rounds(session), (FCOPY)matchRound_flip)
    );
  }

  return session;
}

MatchLeague *match_league (int double_round, int nplayers) {
  return matchLeague_new(
    nplayers / 2,
    match_session(double_round, nplayers),
    matchRsSession_new()
  );
}

/// Adds result of a round.
void match_add (MatchLeague *league, MatchRsRound *results) {
  MatchSession *session = matchLeague_session(league);
  MatchRsSession *session_rs = matchLeague_results(league);

  // Arr<MatchRsRound>
  Arr *rounds_rs = matchRsSession_rounds(session_rs);

  if (matchRsSession_n(session_rs) >= matchSession_n(session))
    EXC_ILLEGAL_STATE(str_f(
      "results round (%d) >= total rounds (%d)",
      matchRsSession_n(session_rs), matchSession_n(session)
    ))

  if (matchLeague_mpr(league) != matchRsRound_n(results))
    EXC_ILLEGAL_STATE(str_f(
      "results (%d) != matches (%d)",
      matchRsRound_n(results), matchLeague_mpr(league)
    ))

  arr_push(rounds_rs, results);
}

int match_next_round_ix (MatchLeague *league) {
  return matchRsSession_n(matchLeague_results(league));
}

MatchRound *match_next_round (MatchLeague *league) {
  int ix = match_next_round_ix(league);
  int max = matchSession_n(matchLeague_session(league));
  EXC_RANGE(ix, 0, max - 1)

  return arr_get(matchSession_rounds(matchLeague_session(league)), ix);
}

Arr *match_maches_results (MatchLeague *league, int ix) {
  int max = match_next_round_ix(league);
  EXC_RANGE(ix, 0, max - 1);

  // Arr<MatchRound>
  Arr *rounds = matchSession_rounds(matchLeague_session(league));
  // Arr<MatchRsRound>
  Arr *rounds_rs = matchRsSession_rounds(matchLeague_results(league));

  // Arr<MatchPlayers>
  Arr *players = matchRound_efective_matches(arr_get(rounds, ix));
  // Arr<MatchResult>
  Arr *rss = matchRsRound_matches(arr_get(rounds_rs, ix));

  // pr is Tp<MatchPlayers, MatchResult>
  MatchPR *fmap(Tp *pr) { return matchPR_new(tp_e1(pr), tp_e2(pr)); }
  return arr_map(arr_zip(players, rss), (FCOPY)fmap);
}

Arr *match_standings_before (MatchLeague *league, int ix) {
  int max = match_next_round_ix(league);
  EXC_RANGE(ix, 0, max);

  MatchSession *session = matchLeague_session(league);
  MatchRsSession *session_rs = matchLeague_results(league);

  // Arr<MatchRound>
  Arr *rounds = matchSession_rounds(session);
  // Arr<MatchStanding>
  Arr *r = arr_new();
  EACH(matchRound_matches(arr_get(rounds, 0)), MatchPlayers, match) {
    if (matchPlayers_up(match) > -1)
      arr_push(r, matchStanding_new(matchPlayers_up(match), 0, 0));
    if (matchPlayers_down(match) > -1)
      arr_push(r, matchStanding_new(matchPlayers_down(match), 0, 0));
  }_EACH

  // Arr<MatchRsRound>
  Arr *rounds_rs = matchRsSession_rounds(session_rs);

  // pr is Tp<MatchPlayers, MatchResult>
  MatchPR *fmap(Tp *pr) { return matchPR_new(tp_e1(pr), tp_e2(pr)); }
  RANGE0(i, ix) {
    // Arr<MatchPlayers>
    Arr *players = matchRound_efective_matches(arr_get(rounds, i));
    // Arr<MatchResult>
    Arr *rss = matchRsRound_matches(arr_get(rounds_rs, i));
    EACH(arr_map(arr_zip(players, rss), (FCOPY)fmap), MatchPR, pr) {
      int up = matchPlayers_up(matchPR_players(pr));
      int down = matchPlayers_down(matchPR_players(pr));
      enum MatchResultT ers = matchResult_rs(matchPR_result(pr));
      int rs = ers == MATCH_RESULT_UP ? 1
        : ers == MATCH_RESULT_DOWN ? -1
          : 0
      ;
      double rs_points = matchResult_points(matchPR_result(pr));

      matchStanding_add(r, up, 1 + rs, rs_points);
      matchStanding_add(r, down, 1 - rs, -rs_points);
    }_EACH
  }_RANGE

  matchStanding_sort(r);

  return r;
}

Arr *match_standings (MatchLeague *league) {
  return match_standings_before(league, match_next_round_ix (league));
}
