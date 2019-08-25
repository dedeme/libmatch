// Copyright 23-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

/// Match result.

#ifndef DMC_MATCHRESULT_H
  #define DMC_MATCHRESULT_H

#include "dmc/std.h"

/// Result type
enum MatchResultT { MATCH_RESULT_UP, MATCH_RESULT_DOWN, MATCH_RESULT_DRAW };

/*--*/

/// Match result
///   Arguments:
///     rs: enum|MatchResultT
///     points: double
typedef struct MatchResult_MatchResult MatchResult;

///
MatchResult *matchResult_new (enum MatchResultT rs, double points);

/// Final result
enum MatchResultT matchResult_rs (MatchResult *this);

/// Points (+ up win or draw, - down win or draw)
double matchResult_points (MatchResult *this);

///
Js *matchResult_to_js (MatchResult *this);

///
MatchResult *matchResult_from_js (Js *js);

/*--*/

///
char *matchResult_str(MatchResult *this);

#endif
