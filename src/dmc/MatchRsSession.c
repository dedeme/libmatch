// Copyright 23-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "dmc/MatchRsSession.h"

MatchRsSession *matchRsSession_new () {
  return (MatchRsSession *)arr_new();
}

int matchRsSession_n (MatchRsSession *this) {
  return arr_size((Arr *)this);
}

Arr *matchRsSession_rounds (MatchRsSession *this) {
  return (Arr *)this;
}

Js *matchRsSession_to_js (MatchRsSession *this) {
  return arr_to_js((Arr *)this, (FTO)matchRsRound_to_js);
}

MatchRsSession *matchRsSession_from_js (Js *js) {
  return (MatchRsSession *)arr_from_js(js, (FFROM)matchRsRound_from_js);
}
