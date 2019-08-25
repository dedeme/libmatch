// Copyright 24-Aug-2019 ºDeme
// GNU General Public License - V3 <http://www.gnu.org/licenses/>

#include "dmc/MatchPR.h"

/* .
# Tuple players-result of one match.
MatchPR
  players: MatchPlayers
  result: MatchResult
*/

/*--*/

struct MatchPR_MatchPR {
  MatchPlayers *players;
  MatchResult *result;
};

MatchPR *matchPR_new (MatchPlayers *players, MatchResult *result) {
  MatchPR *this = MALLOC(MatchPR);
  this->players = players;
  this->result = result;
  return this;
}

MatchPlayers *matchPR_players (MatchPR *this) {
  return this->players;
}

MatchResult *matchPR_result (MatchPR *this) {
  return this->result;
}

/*--*/

char *matchPR_str (MatchPR *this) {
  return str_f(
    "<%s%s>",
    matchPlayers_str(this->players),
    matchResult_str(this->result)
  );
}
