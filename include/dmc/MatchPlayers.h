// Copyright 23-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

/// Players match.

#ifndef DMC_MATCHPLAYERS_H
  #define DMC_MATCHPLAYERS_H

#include "dmc/std.h"

/*--*/

/// Players match.
///   Arguments:
///     up: int
///     down: int
typedef struct MatchPlayers_MatchPlayers MatchPlayers;

///
MatchPlayers *matchPlayers_new (int up, int down);

/// Player at home.
int matchPlayers_up (MatchPlayers *this);

/// Player out.
int matchPlayers_down (MatchPlayers *this);

///
Js *matchPlayers_to_js (MatchPlayers *this);

///
MatchPlayers *matchPlayers_from_js (Js *js);

/*--*/

/// Returns a new match with players interchaged.
MatchPlayers *matchPlayers_flip(MatchPlayers *this);

///
char *matchPlayers_str(MatchPlayers *this);

#endif
