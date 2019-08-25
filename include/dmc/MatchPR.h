// Copyright 24-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

/// Tuple players-result of one match.

#ifndef DMC_MATCHPR_H
  #define DMC_MATCHPR_H

#include "dmc/std.h"
#include "dmc/MatchPlayers.h"
#include "dmc/MatchResult.h"

/*--*/

/// Tuple players-result of one match.
///   Arguments:
///     players: MatchPlayers
///     result: MatchResult
typedef struct MatchPR_MatchPR MatchPR;

///
MatchPR *matchPR_new (MatchPlayers *players, MatchResult *result);

///
MatchPlayers *matchPR_players (MatchPR *this);

///
MatchResult *matchPR_result (MatchPR *this);

/*--*/

///
char *matchPR_str (MatchPR *this);

#endif
