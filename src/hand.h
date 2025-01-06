#ifndef HAND_C
#define HAND_C

#include <stdlib.h>
#include <string.h>

#include "random.h"

extern const size_t HAND_SIZE;
enum Hand
{
    HAND_ROCK,
    HAND_PAPER,
    HAND_SCISSORS,
    HAND_SPOCK,
    HAND_LIZARD
};

enum Hand Hand_fromChar(char c);
enum Hand Hand_getRandom(void);
enum Hand Hand_getRandomChildrenMode(enum Hand player, unsigned long long wins, unsigned long long losses);
enum Hand Hand_getRandomLosingHand(enum Hand winning);
const char *Hand_getWinningInteractionString(enum Hand winner, enum Hand loser);
const char *Hand_toString(enum Hand hand);

#endif
