#include "outcome.h"

static int hasWonWithOffset(enum Hand this, enum Hand against, size_t winningOffset)
{
    return (size_t)this == ((size_t)against + winningOffset) % HAND_SIZE;
}

static int hasWon(enum Hand this, enum Hand against)
{
    return hasWonWithOffset(this, against, 1) || hasWonWithOffset(this, against, 3);
}

enum Outcome Outcome_determine(enum Hand player, enum Hand computer)
{
    if (hasWon(player, computer))
        return OUTCOME_PLAYER;
    if (hasWon(computer, player))
        return OUTCOME_COMPUTER;
    return OUTCOME_DRAW;
}

const char *Outcome_toString(enum Outcome outcome)
{
    switch (outcome)
    {
    case OUTCOME_DRAW:
        return "Unentschieden";
    case OUTCOME_PLAYER:
        return "Spieler gewinnt";
    case OUTCOME_COMPUTER:
        return "Computer gewinnt";
    }
}
