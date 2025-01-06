#include "hand.h"

const size_t HAND_SIZE = 5;

enum Hand Hand_fromChar(char c)
{
    return (enum Hand)(c - '1');
}

enum Hand Hand_getRandom(void)
{
    unsigned int randomNumber = getRandomNumber(0, (unsigned int)HAND_SIZE);
    return (enum Hand)randomNumber;
}

enum Hand Hand_getRandomChildrenMode(enum Hand player, unsigned long long wins, unsigned long long losses)
{
    if (wins <= losses)
        return Hand_getRandomLosingHand(player);
    else
        return Hand_getRandom();
}

enum Hand Hand_getRandomLosingHand(enum Hand winning)
{
    unsigned int randomNumber = getRandomNumber(0, 2);
    if (randomNumber % 2 == 0)
        return (enum Hand)(((size_t)winning + 2) % HAND_SIZE);
    else
        return (enum Hand)(((size_t)winning + 4) % HAND_SIZE);
}

const char *Hand_getWinningInteractionString(enum Hand winner, enum Hand loser)
{
    if (winner == HAND_ROCK)
    {
        if (loser == HAND_SCISSORS)
            return "Stein zerstoert Schere";
        if (loser == HAND_LIZARD)
            return "Stein zerstoert Echse";
    }

    if (winner == HAND_PAPER)
    {
        if (loser == HAND_SPOCK)
            return "Papier widerlegt Spock";
        if (loser == HAND_ROCK)
            return "Papier bedeckt Stein";
    }

    if (winner == HAND_SCISSORS)
    {
        if (loser == HAND_LIZARD)
            return "Schere koepft Echse";
        if (loser == HAND_PAPER)
            return "Schere schneidet Papier";
    }

    if (winner == HAND_LIZARD)
    {
        if (loser == HAND_PAPER)
            return "Echse isst Papier";
        if (loser == HAND_SPOCK)
            return "Echse vergiftet Spock";
    }

    if (winner == HAND_SPOCK)
    {
        if (loser == HAND_ROCK)
            return "Spock verdampft Stein";
        if (loser == HAND_SCISSORS)
            return "Spock zertruemmert Schere";
    }

    return NULL;
}

const char *Hand_toString(enum Hand hand)
{
    switch (hand)
    {
    case HAND_ROCK:
        return "Stein";
    case HAND_PAPER:
        return "Papier";
    case HAND_SCISSORS:
        return "Schere";
    case HAND_SPOCK:
        return "Spock";
    case HAND_LIZARD:
        return "Echse";
    }
}
