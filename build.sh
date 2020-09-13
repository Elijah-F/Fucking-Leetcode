#!/bin/bash

if [ -f "./main" ];then
  rm main
  echo "==== delete old main! ===="
fi

if [ -d "./build/" ];then
  rm -rf build/
  echo "==== delete old build/! ===="
fi

mkdir build
cd build
cmake -j4 ..
make
mv main ..
cd ..
rm -rf build/
