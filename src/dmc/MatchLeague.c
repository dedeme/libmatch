// Copyright 23-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "dmc/MatchLeague.h"

/* .
# One complete league.
MatchLeague: serial
  # Number of matches per round
  mpr: int
  # Rounds.
  session: MatchSession
  # Results.
  results: MatchRsSession
*/
/*--*/

struct MatchLeague_MatchLeague {
  int mpr;
  MatchSession *session;
  MatchRsSession *results;
};

MatchLeague *matchLeague_new (int mpr, MatchSession *session, MatchRsSession *results) {
  MatchLeague *this = MALLOC(MatchLeague);
  this->mpr = mpr;
  this->session = session;
  this->results = results;
  return this;
}

int matchLeague_mpr (MatchLeague *this) {
  return this->mpr;
}

MatchSession *matchLeague_session (MatchLeague *this) {
  return this->session;
}

MatchRsSession *matchLeague_results (MatchLeague *this) {
  return this->results;
}

Js *matchLeague_to_js (MatchLeague *this) {
  // Arr[Js]
  Arr *js = arr_new();
  arr_push(js, js_wi((int)this->mpr));
  arr_push(js, matchSession_to_js(this->session));
  arr_push(js, matchRsSession_to_js(this->results));
  return js_wa(js);
}

MatchLeague *matchLeague_from_js (Js *js) {
  // Arr[Js]
  Arr *a = js_ra(js);
  Js **p = (Js **)arr_start(a);
  MatchLeague *this = MALLOC(MatchLeague);
  this->mpr = js_ri(*p++);
  this->session = matchSession_from_js(*p++);
  this->results = matchRsSession_from_js(*p++);
  return this;
}

/*--*/
