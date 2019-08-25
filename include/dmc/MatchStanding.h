// Copyright 24-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

/// Standing data of one player.

#ifndef DMC_MATCHSTANDING_H
  #define DMC_MATCHSTANDING_H

#include "dmc/std.h"

 /*--*/

/// Standing data of one player.
///   Arguments:
///     player: int
///     points: int
///     tiebreak: double
typedef struct MatchStanding_MatchStanding MatchStanding;

///
MatchStanding *matchStanding_new (int player, int points, double tiebreak);

///
int matchStanding_player (MatchStanding *this);

///
int matchStanding_points (MatchStanding *this);

///
double matchStanding_tiebreak (MatchStanding *this);

 /*--*/

/// Adds points and tiebreak to a player. 'list' is Arr<MatchStaching>.
/// 'points' and 'tiebreak' can be zero or negative.
void matchStanding_add (Arr *list, int player, int points, double tiebreak);

/// Sorts from more to less points 'list'. 'list' is Arr<MatchStaching>.
void matchStanding_sort (Arr *list);

///
char *matchStanding_str (MatchStanding *this);

#endif
