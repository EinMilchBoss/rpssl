#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#include "../src/random.h"

int main(void)
{
    srand((unsigned int)time(NULL));

    unsigned int fromInclusive = 2;
    unsigned int toExclusive = 10;

    size_t occurrencesLength = toExclusive - fromInclusive;
    size_t occurrences[occurrencesLength];
    memset(occurrences, 0, occurrencesLength * sizeof(size_t));

    size_t runs = 1000000000;
    for (size_t i = 0; i < runs; i++)
    {
        unsigned int randomNumber = getRandomNumber(fromInclusive, toExclusive);
        if (randomNumber < fromInclusive || toExclusive <= randomNumber)
        {
            printf("Wrong number: %u\n", randomNumber);
        }
        occurrences[randomNumber - fromInclusive]++;
    }

    for (size_t i = fromInclusive; i < toExclusive; i++)
    {
        size_t occurrence = occurrences[i - fromInclusive];
        printf("%lu: %lu (%.2lf)\n", i, occurrence, (double)occurrence / (double)runs * 100.);
    }

    return 0;
}
