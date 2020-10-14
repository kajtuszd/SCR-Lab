#!/bin/bash

mask=$1
time=$2
file=$3
echo "$@"
find . -type f -mtime -${time} -name "$mask" | xargs tar  -czf $file.tar.gz 
