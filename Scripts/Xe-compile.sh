#!/bin/bash

export compiler=tcc
export cxx=g++

echo Compiling ACE software with C compiler $compiler and Cxx compiler $cxx
echo
echo
echo
echo Continuing in 5 seconds...
sleep 5

capps=(dwm st compton slstatus svkbd)
for a in "${capps[@]}"; do
	echo Compiling $a
	cd ~/ACE/$a
	sudo make clean install CC=$compiler
done

echo ALL DONE
