# About

A simple Rock-Paper-Scissor-Spock-Lizard (short: RPSSL) game that can be played over the terminal.

# Build

This repository was build on MacOS using GCC (or rather clang) version 16.0.0 (clang-1600.0.26.3).

```
chmod +x ./compile.sh
./compile.sh
```

# Run

After you built the executable, run the following command in your terminal:

```bash
./rpssl.exe
```

# Tests

There is only one test regarding the custom random number generator in "random.c". This test can be executed by doing the following:

```bash
chmod +x ./test/random_test.sh
./test/random_test.sh
```