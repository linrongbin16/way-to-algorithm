#! /usr/bin/env bash

if [ -d .bin ]; then
    rm -rf .bin
fi


mkdir .bin
cd .bin
cmake ..
make -j8

cd sort
./sort-insert_sort.exe
./sort-bubble_sort.exe
./sort-merge_sort.exe
./sort-quick_sort.exe
