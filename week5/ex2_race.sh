#!/bin/bash

while true;
do
	LAST_CHAR=$(tail -1 file.txt | grep -Eo '[0-9]+$')
	LAST_CHAR=$(($LAST_CHAR + 1))
	echo $LAST_CHAR >> file.txt 
done

