#!/bin/sh
LC_ALL=C
DATE=`date` ; echo "Aktualna data: ${DATE}"
set `date`
DAY=$1
if [ ${DAY} = 'sob,' ] || [ ${DAY} = 'nie,' ]
then
	echo "Jest weekend"
else
	echo "Jest dzien roboczy"
fi
exit


