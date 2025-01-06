#!/bin/sh

# Remove compiled program if it already exists.
if [ -f ./test/random_test ]; then
    rm ./test/random_test
fi

gcc -Wall -Wpedantic -Wextra -Wconversion ./src/random.c ./test/random_test.c -o ./test/random_test
./test/random_test