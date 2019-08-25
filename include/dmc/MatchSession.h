// Copyright 23-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

/// One complete session.

#ifndef DMC_MATCHSESSION_H
  #define DMC_MATCHSESSION_H

#include "dmc/std.h"
#include "dmc/MatchRound.h"

///
typedef struct matchSession_MatchSession MatchSession;

///
MatchSession *matchSession_new ();

/// Rounds number
int matchSession_n (MatchSession *this);

/// Arr<MatchRound> Rounds
Arr *matchSession_rounds (MatchSession *this);

///
Js *matchSession_to_js (MatchSession *this);

///
MatchSession *matchSession_from_js (Js *js);

#endif
