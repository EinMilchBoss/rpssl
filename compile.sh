#!/bin/sh

# Remove compiled program if it already exists.
if [ -f ./rpssl ]; then
    rm ./rpssl
fi

gcc -Wall -Wpedantic -Wextra -Wconversion ./src/random.c -o ./out/random.o -c
gcc -Wall -Wpedantic -Wextra -Wconversion ./src/hand.c -o ./out/hand.o -c
gcc -Wall -Wpedantic -Wextra -Wconversion ./src/outcome.c -o ./out/outcome.o -c
gcc -Wall -Wpedantic -Wextra -Wconversion ./src/main.c -o ./out/main.o -c
gcc -o ./rpssl ./out/random.o ./out/hand.o ./out/outcome.o ./out/main.o