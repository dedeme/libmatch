// Copyright 23-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

/// One complete session results.

#ifndef DMC_MATCHRSSESSION_H
  #define DMC_MATCHRSSESSION_H

#include "dmc/std.h"
#include "dmc/MatchRsRound.h"

///
typedef struct matchRsSession_MatchRsSession MatchRsSession;

///
MatchRsSession *matchRsSession_new ();

/// Rounds number
int matchRsSession_n (MatchRsSession *this);

/// Arr<MatchRsRound> Rounds
Arr *matchRsSession_rounds (MatchRsSession *this);

///
Js *matchRsSession_to_js (MatchRsSession *this);

///
MatchRsSession *matchRsSession_from_js (Js *js);

#endif
