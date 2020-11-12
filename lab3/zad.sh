#!/bin/bash
x=1;

while [ $x -le 100000000000000000 ] ; do
	x=$[x + 1]
	sleep 1s
done
