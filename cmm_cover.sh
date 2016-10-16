#!/bin/bash

rm -rf ./_gcov
mkdir _gcov
cd _gcov

CMMROOT=..

gcc -Wall -fprofile-arcs -ftest-coverage -I $CMMROOT/src -o $CMMROOT/_gcov/hello \
    $CMMROOT/src/github.com/ricallinson/testhello/hello.c \
    $CMMROOT/src/github.com/ricallinson/testlib/math.c \
    $CMMROOT/src/github.com/ricallinson/teststruct/account.c

./hello

gcov hello.c math.c account.c
