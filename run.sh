#!/bin/bash

for file in `find -type f | ls "verilator/build/"*.bin`
do
  echo "$file"   
  ./obj_dir/VsimTop $file
done
