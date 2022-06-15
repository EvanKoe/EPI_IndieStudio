#!/bin/bash

if [ "$1" == "re" ]; then
  if [ -d "./build" ]; then
    rm -rf ./build
  fi
  mkdir ./build && cd build
  cmake ..
  cd ..
fi

make -C ./build
cp ./build/bomberman ./bomberman
