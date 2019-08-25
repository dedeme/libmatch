// Copyright 24-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "league_tests.h"
#include <assert.h>
#include "dmc/match.h"

void league_tests (void) {
  puts("League tests:");

  MatchLeague *league = match_league(1, 5);
  MatchSession *session = matchLeague_session(league);

  // Arr<MatchRound>
  Arr *rounds = matchSession_rounds(session);

  assert(str_eq(
    str_join(arr_map(rounds, (FCOPY)matchRound_str), ""),
    "(0--1)(1-4)(2-3)"
    "(0-4)(-1-3)(1-2)"
    "(0-3)(4-2)(-1-1)"
    "(0-2)(3-1)(4--1)"
    "(0-1)(2--1)(3-4)"

    "(-1-0)(4-1)(3-2)"
    "(4-0)(3--1)(2-1)"
    "(3-0)(2-4)(1--1)"
    "(2-0)(1-3)(-1-4)"
    "(1-0)(-1-2)(4-3)"
  ));

  char *fn (int *ix) {
    return str_join(arr_map(
      matchRound_efective_matches(arr_get(rounds, *ix)), (FCOPY)matchPlayers_str
    ), "");
  }
  assert(str_eq(
    str_join(
      it_to(it_map(it_range0(matchSession_n(session)), (FCOPY)fn)
    ), ""),
    "(1-4)(2-3)"
    "(0-4)(1-2)"
    "(0-3)(4-2)"
    "(0-2)(3-1)"
    "(0-1)(3-4)"

    "(4-1)(3-2)"
    "(4-0)(2-1)"
    "(3-0)(2-4)"
    "(2-0)(1-3)"
    "(1-0)(4-3)"
  ));

  // -------------------------------------

  match_add(league, matchRsRound_new_from(
    matchResult_new (MATCH_RESULT_UP, 3.5),
    matchResult_new (MATCH_RESULT_DRAW, 0),
    NULL
  ));

  assert(str_eq(
    str_join(arr_map(match_maches_results(league, 0), (FCOPY)matchPR_str), ""),
    "<(1-4)[1, 3.5000]><(2-3)[X, 0.0000]>"
  ));

  char *stds0 = str_join(
    arr_map(match_standings(league), (FCOPY)matchStanding_str), ""
  );
  assert(str_eq(
    stds0,
    "<1 = 2(3.5000)>"
    "<2 = 1(0.0000)>"
    "<3 = 1(0.0000)>"
    "<0 = 0(0.0000)>"
    "<4 = 0(-3.5000)>"
  ));

  // -------------------------------------

  match_add(league, matchRsRound_new_from(
    matchResult_new (MATCH_RESULT_DOWN, -2.75),
    matchResult_new (MATCH_RESULT_DRAW, 0),
    NULL
  ));

  assert(str_eq(
    str_join(arr_map(match_maches_results(league, 0), (FCOPY)matchPR_str), ""),
    "<(1-4)[1, 3.5000]><(2-3)[X, 0.0000]>"
  ));
  assert(str_eq(
    str_join(arr_map(match_maches_results(league, 1), (FCOPY)matchPR_str), ""),
    "<(0-4)[2, -2.7500]><(1-2)[X, 0.0000]>"
  ));

  assert(str_eq(stds0, str_join(
    arr_map(match_standings_before(league, 1), (FCOPY)matchStanding_str), ""
  )));

  char *stds1 = str_join(
    arr_map(match_standings(league), (FCOPY)matchStanding_str), ""
  );
  assert(str_eq(
    stds1,
    "<1 = 3(3.5000)>"
    "<2 = 2(0.0000)>"
    "<4 = 2(-0.7500)>"
    "<3 = 1(0.0000)>"
    "<0 = 0(-2.7500)>"
  ));

  // -------------------------------------

  league = match_league(1, 5);

  // Arr<char>
  Arr *rrs = str_csplit(
    "1;3.5:x;0|"
    "2;-2.75:x;0|"
    "x;0:x;0|"
    "1;1.5:1;0.25|"
    "2;-1.5:2;-75|"

    "1;3.5:x;0|"
    "2;-2.75:x;0|"
    "x;0:x;0|"
    "1;1.5:1;0.25|"
    "2;-1.5:2;-75",
    '|'
  );

  MatchResult *mr_mk (char *s) {
    char **ps = (char **)arr_start(str_csplit(s, ';'));
    int r = *ps[0] == '1' ? MATCH_RESULT_UP
      : *ps[0] == 'x' ? MATCH_RESULT_DRAW
        : MATCH_RESULT_DOWN;
    return matchResult_new(r, atof(ps[1]));
  }
  EACH(rrs, char, rr) {
    char **mrss = (char **)arr_start(str_csplit(rr, ':'));

    match_add(league, matchRsRound_new_from(
      mr_mk(mrss[0]), mr_mk(mrss[1]), NULL
    ));
  }_EACH

  assert(str_eq(stds0, str_join(
    arr_map(match_standings_before(league, 1), (FCOPY)matchStanding_str), ""
  )));
  assert(str_eq(stds1, str_join(
    arr_map(match_standings_before(league, 2), (FCOPY)matchStanding_str), ""
  )));

  char *stds = str_join(
    arr_map(match_standings(league), (FCOPY)matchStanding_str), ""
  );
  assert(str_eq(
    stds,
    "<2 = 8(0.0000)>"
    "<1 = 8(0.0000)>"
    "<0 = 8(0.0000)>"
    "<4 = 8(0.0000)>"
    "<3 = 8(0.0000)>"
  ));

  TRY {
    match_add(league, matchRsRound_new_from(
      matchResult_new (MATCH_RESULT_DOWN, -2.75),
      matchResult_new (MATCH_RESULT_DRAW, 0),
      NULL
    ));
    assert(0);
  } CATCH(e) {
    // puts(exc_msg(e));
    assert(*exc_msg(e));
  }_TRY

  puts("    Finished");
}
