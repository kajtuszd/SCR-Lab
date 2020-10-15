#!/bin/bash

help() { echo "Help: $0 [-m <maska pliku>] [-n <czas istnienia pliku>] [-a <nazwa archiwum>]"; exit 1;}

time=""
mask=""
file=""

while getopts ":m:n:a:" opt; do
	case $opt in
		
		m)
			mask="$OPTARG"
			;;
		n)
			time=$OPTARG
			;;
		a)
			file=$OPTARG
			;;
		*)
			help
			;;
	esac
done
if [[ ""=$mask ]]; then echo "Podaj maske pliku: "; read mask; fi
if [[ ""=$time ]]; then echo "Podaj czas istnienia pliku: "; read time; fi
if [[ ""=$file ]]; then echo "Podaj nazwe archiwum: "; read file; fi			
		
find . -type f -mtime -$time -name "$mask" | xargs tar  -czf $file.tar.gz 

echo "Spakowano pomyslnie"


