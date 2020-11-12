#!/bin/bash
x=1;

while [ $x -le 100 ] ; do
	echo $x
	x=$[x + 1]
	sleep 1s
done