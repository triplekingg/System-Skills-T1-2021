#!/bin/bash
zipped="$1"
path="$2"
if test -d "$path"; then
    unzip $1 -d $2 
else
    mkdir $2
    unzip $1 -d $2 
fi
cd $path
find . -mindepth 2 -type f -print -exec mv {} . \;
rm -r */