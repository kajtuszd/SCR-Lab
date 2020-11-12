#!/bin/bash
a=1;

trap 'print "Control-C cannot terminate this script."' INT
trap 'print "Control-Z cannot terminate this script."' EXIT

while [ $a -le 10000 ] ; do
	echo "Rolling...."
	a=$[a + 1]
	sleep 1s
done