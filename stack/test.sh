#!/usr/bin/env bash

test="$(cat output.txt)";

for d in * ; do

    if ! [ -d "$d" ]; then continue; fi;

    cd "$d" || exit;

    output="$(bash run.sh)";
    if [ "$output" = "$test" ]; then
        echo "ok $d"
    else
        echo "erro na pasta $d, exibindo diff:"
        bash run.sh | diff ../output.txt -
    fi

    cd ..
done
