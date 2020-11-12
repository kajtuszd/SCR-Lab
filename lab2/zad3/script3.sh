#!/bin/bash
x=1;
read word

while [ $x -le 5 ] ; do
	echo $x
	x=$[x + 1]
	sleep 1s
done

echo $word
