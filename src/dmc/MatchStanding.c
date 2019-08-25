// Copyright 24-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "dmc/MatchStanding.h"

/* .
# Standing data of one player.
MatchStanding:
  player: int
  points: int
  tiebreak: double
*/

/*--*/

struct MatchStanding_MatchStanding {
  int player;
  int points;
  double tiebreak;
};

MatchStanding *matchStanding_new (int player, int points, double tiebreak) {
  MatchStanding *this = MALLOC(MatchStanding);
  this->player = player;
  this->points = points;
  this->tiebreak = tiebreak;
  return this;
}

int matchStanding_player (MatchStanding *this) {
  return this->player;
}

int matchStanding_points (MatchStanding *this) {
  return this->points;
}

double matchStanding_tiebreak (MatchStanding *this) {
  return this->tiebreak;
}

/*--*/

void matchStanding_add (Arr *list, int player, int points, double tiebreak) {
  int fn (MatchStanding *std) { return std->player == player; }
  int ix = arr_index(list, (FPRED)fn);
  if (ix == -1)
    EXC_ILLEGAL_STATE(str_f("Player '%d' not found", player))

  MatchStanding *std = arr_get(list, ix);
  arr_remove(list, ix);
  arr_push(list, matchStanding_new(
    player, std->points + points, std->tiebreak + tiebreak
  ));
}

/// Sorts from more to less points 'list'. 'list' is Arr<MatchStaching>.
void matchStanding_sort (Arr *list) {
  int fgreater (MatchStanding *s1, MatchStanding *s2) {
    if (s1->points == s2 -> points) return s2->tiebreak > s1->tiebreak;
    else return s2->points > s1->points;
  }
  arr_sort(list, (FCMP)fgreater);
}

char *matchStanding_str (MatchStanding *this) {
  return str_f("<%d = %d(%.4f)>", this->player, this->points, this->tiebreak);
}
