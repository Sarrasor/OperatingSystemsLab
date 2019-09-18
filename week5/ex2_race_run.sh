#!/bin/bash

echo 0 > file.txt

./ex2_race.sh & ./ex2_race.sh
