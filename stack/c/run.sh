#!/usr/bin/env sh

gcc -o ./test.out stack.c &&
    out="$(./test.out)" &&
    rm ./test.out &&
    echo "$out"
