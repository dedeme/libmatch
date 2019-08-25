// Copyright 23-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "dmc/MatchRsRound.h"

MatchRsRound *matchRsRound_new () {
  return (MatchRsRound *)arr_new();
}

MatchRsRound *matchRsRound_new_from (MatchResult *rs, ...) {
  va_list args;
  void *tmp;

  // Arr<MatchResult>
  Arr *this = arr_new();
  arr_push(this, rs);

  va_start(args, rs);
  tmp = va_arg(args, void *);
  while (tmp) {
    arr_push(this, tmp);
    tmp = va_arg(args, void *);
  }
  va_end(args);

  return (MatchRsRound *)this;
}

int matchRsRound_n (MatchRsRound *this) {
  return arr_size((Arr *)this);
}

Arr *matchRsRound_matches (MatchRsRound *this) {
  return (Arr *)this;
}

Js *matchRsRound_to_js (MatchRsRound *this) {
  return arr_to_js((Arr *)this, (FTO)matchResult_to_js);
}

MatchRsRound *matchRsRound_from_js (Js *js) {
  return (MatchRsRound *)arr_from_js(js, (FFROM)matchResult_from_js);
}

char *matchRsRound_str(MatchRsRound *this) {
  return str_join(arr_map((Arr *)this, (FCOPY)matchResult_str), "");
}
