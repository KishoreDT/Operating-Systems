#!/bin/bash
read -p "Enter file name :" a
read -p "Enter starting line number :" x
read -p "Enter ending line number :" y
read -p "Enter word need to be replaced :" txt1 txt2
sed "$x,$y s/$txt1/$txt2/g" $a