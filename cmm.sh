#!/bin/bash

CMMROOT=./

gcc -I $CMMROOT/src -o $CMMROOT/bin/hello \
    $CMMROOT/src/github.com/ricallinson/testhello/hello.c \
    $CMMROOT/src/github.com/ricallinson/testlib/math.c \
    $CMMROOT/src/github.com/ricallinson/teststruct/account.c
