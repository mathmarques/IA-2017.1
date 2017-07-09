#!/bin/bash

mkdir results
declare -a arr=("puzz2_worst.txt" "puzz3_worst.txt" "puzz4_worst.txt" "puzz5_worst.txt" "puzz6_worst.txt" "puzz7_worst.txt")

if [ ! -e "${1}" ]; then
  echo "File: ${1} not Found!"
else
  for file in "${arr[@]}"
  do
    ./PuzzleSolver -debug ${1} Tests/$file
  done
fi
