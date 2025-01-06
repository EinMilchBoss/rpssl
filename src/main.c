#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hand.h"
#include "outcome.h"

int isChildrenMode(void)
{
    char *childrenModeValue = getenv("RPSSL_CHILDREN_MODE");
    return childrenModeValue != NULL && strcmp(childrenModeValue, "0") != 0;
}

void printGameInformation(void)
{
    printf("Rock Paper Scissors Spock Lizard\n");
    printf("********************************\n");
    printf("\n");

    for (size_t w = 0; w < HAND_SIZE; w++)
    {
        for (size_t l = 0; l < HAND_SIZE; l++)
        {
            const char *const interaction = Hand_getWinningInteractionString((enum Hand)w, (enum Hand)l);
            if (interaction == NULL)
                continue;

            printf("%s\n", interaction);
        }
    }

    printf("\n");
    printf("\n");
}

void printSettings(void) 
{
    printf("Settings:\n");
    printf("*********\n");
    printf("Children Mode: %s\n", isChildrenMode() ? "ON" : "OFF");
    printf("\n");
    printf("\n");
}

void printPossibleHands(void)
{
    printf("0 - Beenden\n");

    for (size_t i = 0; i < HAND_SIZE; i++)
    {
        printf("%lu - %s\n", i + 1, Hand_toString((enum Hand)i));
    }
}

int main(void)
{
    srand((unsigned int)time(NULL));

    printGameInformation();
    printSettings();

    unsigned long long wins = 0;
    unsigned long long losses = 0;

    char input = 0;
    while (1)
    {
        printPossibleHands();
        printf("Ihre Wahl: ");
        // The leading space is necessary to ignore all leading spaces.
        scanf(" %c", &input);

        if (input < '0' || '5' < input)
        {
            printf("Ungueltige Eingabe.\n\n");
            continue;
        }

        if (input == '0')
            break;

        enum Hand player = Hand_fromChar(input);
        printf("Spieler waehlt %s\n", Hand_toString(player));

        enum Hand computer = isChildrenMode()
                                 ? Hand_getRandomChildrenMode(player, wins, losses)
                                 : Hand_getRandom();
        printf("Computer waehlt %s\n", Hand_toString(computer));

        enum Outcome outcome = Outcome_determine(player, computer);
        if (outcome == OUTCOME_PLAYER)
        {
            printf("%s - ", Hand_getWinningInteractionString(player, computer));
            wins++;
        }
        if (outcome == OUTCOME_COMPUTER)
        {
            printf("%s - ", Hand_getWinningInteractionString(computer, player));
            losses++;
        }
        printf("%s!\n\n", Outcome_toString(outcome));
    };

    printf("Spiel beendet. Siege: %llu, Niederlagen: %llu.\n", wins, losses);
    return 0;
}
