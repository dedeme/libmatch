// Copyright 23-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

/// One complete league.

#ifndef DMC_MATCHLEAGUE_H
  #define DMC_MATCHLEAGUE_H

#include "dmc/std.h"
#include "dmc/MatchSession.h"
#include "dmc/MatchRsSession.h"

/*--*/

/// One complete league.
///   Arguments:
///     mpr: int
///     session: MatchSession
///     results: MatchRsSession
typedef struct MatchLeague_MatchLeague MatchLeague;

///
MatchLeague *matchLeague_new (int mpr, MatchSession *session, MatchRsSession *results);

/// Number of matches per round
int matchLeague_mpr (MatchLeague *this);

/// Rounds.
MatchSession *matchLeague_session (MatchLeague *this);

/// Results.
MatchRsSession *matchLeague_results (MatchLeague *this);

///
Js *matchLeague_to_js (MatchLeague *this);

///
MatchLeague *matchLeague_from_js (Js *js);

/*--*/

#endif
