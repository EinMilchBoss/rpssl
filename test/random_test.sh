#!/bin/sh

gcc -Wall -Wpedantic -Wextra -Wconversion ./src/random.c ./test/random_test.c -o ./test/random_test.exe
./test/random_test.exe