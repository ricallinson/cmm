#!/bin/bash

CMMROOT=.

# Copy all *.c files into the "pkg" directory and generate the *.h files.

gcc -I $CMMROOT/pkg -o $CMMROOT/bin/testhello \
    $CMMROOT/pkg/github.com/ricallinson/testhello/hello.c \
    $CMMROOT/pkg/github.com/ricallinson/testlib/math.c \
    $CMMROOT/pkg/github.com/ricallinson/teststruct/account.c
