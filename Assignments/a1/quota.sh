#!/bin/bash
path="$1"
size=$(du -s -m $path | cut -f1)
if [ $size -le 1 ] && [ $size -gt 0 ] 
then
   echo "Low"
elif [ $size -lt 5 ] && [ $size -gt 1 ] 
then
   echo "Medium"
else
   echo "High"
   echo "$1" >> ~/ListOfBigDirs.txt
fi
