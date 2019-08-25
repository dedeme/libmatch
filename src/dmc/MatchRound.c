// Copyright 23-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "dmc/MatchRound.h"

MatchRound *matchRound_new () {
  return (MatchRound *)arr_new();
}

int matchRound_n (MatchRound *this) {
  return arr_size((Arr *)this);
}

Arr *matchRound_matches (MatchRound *this) {
  return (Arr *)this;
}

Arr *matchRound_efective_matches (MatchRound *this) {
  int fn (MatchPlayers *m) {
    return matchPlayers_up(m) != -1 && matchPlayers_down(m) != -1;
  }
  return arr_filter_to((Arr *)this, (FPRED)fn);
}

Js *matchRound_to_js (MatchRound *this) {
  return arr_to_js((Arr *)this, (FTO)matchPlayers_to_js);
}

MatchRound *matchRound_from_js (Js *js) {
  return (MatchRound *)arr_from_js(js, (FFROM)matchPlayers_from_js);
}

MatchRound *matchRound_flip(MatchRound *this) {
  return (MatchRound *)arr_map((Arr *)this, (FCOPY)matchPlayers_flip);
}

char *matchRound_str(MatchRound *this) {
  return str_join(arr_map((Arr *)this, (FCOPY)matchPlayers_str), "");
}
