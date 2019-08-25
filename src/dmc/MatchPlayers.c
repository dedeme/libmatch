// Copyright 23-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "dmc/MatchPlayers.h"

/* .
# Players match.
MatchPlayers: serial
  # Player at home.
  up: int
  # Player out.
  down: int
*/

/*--*/

struct MatchPlayers_MatchPlayers {
  int up;
  int down;
};

MatchPlayers *matchPlayers_new (int up, int down) {
  MatchPlayers *this = MALLOC(MatchPlayers);
  this->up = up;
  this->down = down;
  return this;
}

int matchPlayers_up (MatchPlayers *this) {
  return this->up;
}

int matchPlayers_down (MatchPlayers *this) {
  return this->down;
}

Js *matchPlayers_to_js (MatchPlayers *this) {
  // Arr[Js]
  Arr *js = arr_new();
  arr_push(js, js_wi((int)this->up));
  arr_push(js, js_wi((int)this->down));
  return js_wa(js);
}

MatchPlayers *matchPlayers_from_js (Js *js) {
  // Arr[Js]
  Arr *a = js_ra(js);
  Js **p = (Js **)arr_start(a);
  MatchPlayers *this = MALLOC(MatchPlayers);
  this->up = js_ri(*p++);
  this->down = js_ri(*p++);
  return this;
}

/*--*/

MatchPlayers *matchPlayers_flip(MatchPlayers *this) {
  return matchPlayers_new(this->down, this->up);
}

char *matchPlayers_str(MatchPlayers *this) {
  return str_f("(%d-%d)", this->up, this->down);
}
