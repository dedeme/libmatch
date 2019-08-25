// Copyright 23-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "session_tests.h"
#include <assert.h>
#include "dmc/match.h"

void session_tests (void) {
  puts("Session tests:");

  MatchSession *ms = match_session(1, 4);
  assert(matchSession_n(ms) == 6);

  /*
  puts(matchRound_str(arr_get(matchSession_rounds(ms), 0)));
  puts(matchRound_str(arr_get(matchSession_rounds(ms), 1)));
  puts(matchRound_str(arr_get(matchSession_rounds(ms), 2)));
  puts(matchRound_str(arr_get(matchSession_rounds(ms), 3)));
  puts(matchRound_str(arr_get(matchSession_rounds(ms), 4)));
  puts(matchRound_str(arr_get(matchSession_rounds(ms), 5)));
  */

  assert(!strcmp(
    matchRound_str(arr_get(matchSession_rounds(ms), 0)), "(0-3)(1-2)"
  ));
  assert(!strcmp(
    matchRound_str(arr_get(matchSession_rounds(ms), 1)), "(0-2)(3-1)"
  ));
  assert(!strcmp(
    matchRound_str(arr_get(matchSession_rounds(ms), 2)), "(0-1)(2-3)"
  ));
  assert(!strcmp(
    matchRound_str(arr_get(matchSession_rounds(ms), 3)), "(3-0)(2-1)"
  ));
  assert(!strcmp(
    matchRound_str(arr_get(matchSession_rounds(ms), 4)), "(2-0)(1-3)"
  ));
  assert(!strcmp(
    matchRound_str(arr_get(matchSession_rounds(ms), 5)), "(1-0)(3-2)"
  ));

  puts("    Finished");
}



