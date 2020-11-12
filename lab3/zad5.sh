#!/bin/bash
x=1;
trap '' ALRM
trap 'Program finished' TERM


while [ $x -le 10000 ] ; do
	echo "Rolling...."
	x=$[x + 1]
	sleep 1s
done
