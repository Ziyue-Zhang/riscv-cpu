#!/bin/bash

for file in `find -type f | ls "build/"*.bin`
do
   ./test $file
done
