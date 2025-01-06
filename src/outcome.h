#ifndef OUTCOME_H
#define OUTCOME_H

#include <stdlib.h>

#include "hand.h"

enum Outcome
{
    OUTCOME_PLAYER = -1,
    OUTCOME_DRAW = 0,
    OUTCOME_COMPUTER = 1
};

enum Outcome Outcome_determine(enum Hand player, enum Hand computer);
const char *Outcome_toString(enum Outcome outcome);

#endif
