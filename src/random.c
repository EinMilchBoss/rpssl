#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "random.h"

unsigned int getRandomNumber(unsigned int fromInclusive, unsigned int toExclusive)
{
    assert(fromInclusive < toExclusive);

    unsigned int max = RAND_MAX;
    assert(toExclusive <= max);

    unsigned int randomNumber = (unsigned int)rand();
    double norm = (double)randomNumber / (double)max;
    unsigned int range = toExclusive - fromInclusive;
    unsigned int equalizedProbability = (unsigned int)round(range * norm) % range;
    return equalizedProbability + fromInclusive;
}
