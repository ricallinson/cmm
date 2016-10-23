#!/bin/bash

CMMROOT=$(pwd)

rm -rf $CMMROOT/_gcov
mkdir $CMMROOT/_gcov
cd $CMMROOT/_gcov

gcc -Wall -fprofile-arcs -ftest-coverage -I $CMMROOT/src -o $CMMROOT/_gcov/map_test \
    $CMMROOT/src/github.com/ricallinson/testmap/map_test.c \
    $CMMROOT/src/github.com/ricallinson/testmap/map.c

./map_test

gcov map_test.c map.c
