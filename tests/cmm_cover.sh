#!/bin/bash

CMMROOT=$(pwd)

rm -rf $CMMROOT/_gcov
mkdir $CMMROOT/_gcov
cd $CMMROOT/_gcov

# Copy all *.c files into the "pkg" directory and generate the *.h files.

gcc -Wall -fprofile-arcs -ftest-coverage -I $CMMROOT/pkg -o $CMMROOT/_gcov/hello \
    $CMMROOT/pkg/github.com/ricallinson/testhello/hello.c \
    $CMMROOT/pkg/github.com/ricallinson/testlib/math.c \
    $CMMROOT/pkg/github.com/ricallinson/teststruct/account.c

./hello

gcov hello.c math.c account.c
