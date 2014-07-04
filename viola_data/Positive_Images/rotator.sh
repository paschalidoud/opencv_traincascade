#!/bin/bash

a=$1
b=$2
for file in *.jpg; do
    convert "$file" -rotate "$b" -resize 640x480! positive"$a".jpg
    a=$(($a + 1))
done    
