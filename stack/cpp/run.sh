#!/usr/bin/env sh

gcc -o ./test.out stack.cpp &&
    out="$(./test.out)" &&
    rm ./test.out &&
    echo "$out"
