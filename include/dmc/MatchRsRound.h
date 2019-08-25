// Copyright 23-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

/// One session results.

#ifndef DMC_MATCHRSROUND_H
  #define DMC_MATCHRSROUND_H

#include "dmc/std.h"
#include "dmc/MatchResult.h"

///
typedef struct matchRsRound_MatchRsRound MatchRsRound;

///
MatchRsRound *matchRsRound_new ();

/// Returns a new 'MatchRsRound' from a NULL finished list of 'MatchResult'.
MatchRsRound *matchRsRound_new_from (MatchResult *rs, ...);

/// Results number
int matchRsRound_n (MatchRsRound *this);

/// Arr<MatchResult> Results
Arr *matchRsRound_matches (MatchRsRound *this);

///
Js *matchRsRound_to_js (MatchRsRound *this);

///
MatchRsRound *matchRsRound_from_js (Js *js);

///
char *matchRsRound_str(MatchRsRound *this);


#endif
