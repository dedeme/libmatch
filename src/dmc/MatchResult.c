// Copyright 23-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "dmc/MatchResult.h"

/* .
# Match result
MatchResult: serial
  # Final result
  rs: enum MatchResultT
  # Points (+ up win or draw, - down win or draw)
  points: double
*/

/*--*/

struct MatchResult_MatchResult {
  enum MatchResultT rs;
  double points;
};

MatchResult *matchResult_new (enum MatchResultT rs, double points) {
  MatchResult *this = MALLOC(MatchResult);
  this->rs = rs;
  this->points = points;
  return this;
}

enum MatchResultT matchResult_rs (MatchResult *this) {
  return this->rs;
}

double matchResult_points (MatchResult *this) {
  return this->points;
}

Js *matchResult_to_js (MatchResult *this) {
  // Arr[Js]
  Arr *js = arr_new();
  arr_push(js, js_wi((int)this->rs));
  arr_push(js, js_wd(this->points));
  return js_wa(js);
}

MatchResult *matchResult_from_js (Js *js) {
  // Arr[Js]
  Arr *a = js_ra(js);
  Js **p = (Js **)arr_start(a);
  MatchResult *this = MALLOC(MatchResult);
  this->rs = js_ri(*p++);
  this->points = js_rd(*p++);
  return this;
}

/*--*/

char *matchResult_str(MatchResult *this) {
  return str_f(
    "[%s, %.4f]",
    this->rs == MATCH_RESULT_UP ? "1"
      : this->rs == MATCH_RESULT_DOWN ? "2"
        : "X",
    this->points
  );
}
