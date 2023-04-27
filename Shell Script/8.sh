#!/bin/bash
#read -p "Enter file name :" a
read -p "Enter word :" txt1
sed "/$txt1/d" 1.txt