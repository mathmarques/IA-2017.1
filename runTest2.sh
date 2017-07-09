#!/bin/bash

declare -a arr=("puzz2_worst.txt" "puzz3_worst.txt" "puzz4_worst.txt" "puzz5_worst.txt" "puzz6_worst.txt" "puzz7_worst.txt" "puzz8_worst.txt" "puzz9_worst.txt" "puzz10_worst.txt" "puzz11_worst.txt")

  for file in "${arr[@]}"
  do
    ./PuzzleSolver -debug ${1} Tests/$file
  done

  echo " "
