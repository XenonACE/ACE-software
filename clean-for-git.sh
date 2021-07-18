#!/bin/bash

echo Cleaning

capps=(dwm st compton slstatus svkbd display-manager)
for a in "${capps[@]}"; do
	echo Cleaning $a
	cd $a
	make clean
	cd ..
done

echo ALL DONE
