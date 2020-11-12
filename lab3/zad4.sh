#!/bin/bash
x=1;
trap "echo trap" {1..15}
while [ $x -le 10000 ] ; do
	x=$[x+1]
echo " PID:    $$   "
	sleep 1s
done