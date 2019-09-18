#!/bin/bash

rm file.lock

while true;
do
	if ln file.txt file.lock; then
		touch file.lock
		LAST_CHAR=$(tail -1 file.txt | grep -Eo '[0-9]+$')
		LAST_CHAR=$(($LAST_CHAR + 1))
		echo $LAST_CHAR >> file.txt 
		rm file.lock
	else
		echo locked
	fi
done