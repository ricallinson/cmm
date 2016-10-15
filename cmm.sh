#!/bin/bash

CMMROOT=./src

gcc -I $CMMROOT -o ./bin/testhello \
    ./src/github.com/ricallinson/testhello/hello.c \
    ./src/github.com/ricallinson/testlib/math.c
