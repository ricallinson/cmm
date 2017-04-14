#!/bin/bash

CMMROOT=$(pwd)

rm -rf $CMMROOT/_gcov
mkdir $CMMROOT/_gcov
cd $CMMROOT/_gcov

# Copy all *.c files into the "pkg" directory and generate the *.h files.

gcc -Wall -fprofile-arcs -ftest-coverage -I $CMMROOT/pkg -o $CMMROOT/_gcov/map_test \
    $CMMROOT/pkg/github.com/ricallinson/testmap/map_test.c \
    $CMMROOT/pkg/github.com/ricallinson/testmap/map.c

./map_test

gcov map_test.c map.c
