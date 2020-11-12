#!/bin/bash
x=1;
trap 'print "Ctrl-C cannot terminate this script."' INT
trap 'print "kill -quit cannot terminate this script."' QUIT
trap 'print "kill -ill cannot terminate this script."' ILL
trap 'print "kill -fpe cannot terminate this script."' FPE

while [ $x -le 10000 ] ; do
	echo "Rolling...."
	x=$[x + 1]
	sleep 1s
done
