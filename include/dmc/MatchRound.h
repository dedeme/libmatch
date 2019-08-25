// Copyright 23-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

/// One session round.

#ifndef DMC_MATCHROUND_H
  #define DMC_MATCHROUND_H

#include "dmc/std.h"
#include "dmc/MatchPlayers.h"

///
typedef struct matchRound_MatchRound MatchRound;

///
MatchRound *matchRound_new ();

/// Matches number
int matchRound_n (MatchRound *this);

/// Arr<MatchPlayers> Matches
Arr *matchRound_matches (MatchRound *this);

/// Arr<MatchPlayers> Matches excluded 'resting' match if exists.
Arr *matchRound_efective_matches (MatchRound *this);

///
Js *matchRound_to_js (MatchRound *this);

///
MatchRound *matchRound_from_js (Js *js);

/// Returns a new MatchRound equals to this but with payers interchanged in
/// each match.
MatchRound *matchRound_flip(MatchRound *this);

///
char *matchRound_str(MatchRound *this);

#endif
