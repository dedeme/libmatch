// Copyright 23-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

/// Main file.

#ifndef DMC_MATCH_H
  #define DMC_MATCH_H

#include "dmc/std.h"
#include "dmc/MatchLeague.h"
#include "dmc/MatchStanding.h"
#include "dmc/MatchPR.h"

/// Generate a complete session.
///   double_round: It is 'true' if there is a double round.
///   nplayers    : Number of players.
MatchSession *match_session (int double_round, int nplayers);

/// Creates a new league.
/// The league has no results. This should be added with 'match_add'.
MatchLeague *match_league (int double_round, int nplayers);

/// Adds result of a round.
void match_add (MatchLeague *league, MatchRsRound *results);

/// Returns next round index. (0 based index).
/// NOTE: If 'match_next_round_ix' is equals to the total of rounds, 'legue' is
///       finished.
int match_next_round_ix (MatchLeague *league);

/// Returns next round.
MatchRound *match_next_round (MatchLeague *league);

/// Arr<MatchPR> Returns matches and results of round 'ix'.
/// 'ix' must be less than 'match_next_round_ix()'.
Arr *match_maches_results (MatchLeague *league, int ix);

/// Arr<MatchStanding> Returns players standings from up to dawn before round
/// 'ix'.
/// 'ix' must be less or equals to 'match_next_round_ix()'.
Arr *match_standings_before (MatchLeague *league, int ix);

/// Arr<MatchStanding> Returns players standings from up to dawn after the
/// last round played.
Arr *match_standings (MatchLeague *league);

#endif
