#!/bin/bash
a=1;
while [ $a -le 10000 ] ; do
	echo "$a"
	a=$[a + 1]
	sleep 1s
done