// Copyright 23-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "dmc/MatchSession.h"

MatchSession *matchSession_new () {
  return (MatchSession *)arr_new();
}

int matchSession_n (MatchSession *this) {
  return arr_size((Arr *)this);
}

Arr *matchSession_rounds (MatchSession *this) {
  return (Arr *)this;
}

Js *matchSession_to_js (MatchSession *this) {
  return arr_to_js((Arr *)this, (FTO)matchRound_to_js);
}

MatchSession *matchSession_from_js (Js *js) {
  return (MatchSession *)arr_from_js(js, (FFROM)matchRound_from_js);
}
