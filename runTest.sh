#!/bin/bash

mkdir results
declare -a arr=("BT" "BFS" "DFS" "OS" "GS" "AS" "IDA")

if [ ! -e "${1}" ]; then
  echo "File: ${1} not Found!"
else
  for alg in "${arr[@]}"
  do
    echo "Executing $alg for ${2} (${1})" | tee -a results/$alg.txt results/${2}.txt
    ./PuzzleSolver $alg ${1} | tee -a results/$alg.txt results/${2}.txt
  done
fi
