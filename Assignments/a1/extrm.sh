#!/bin/bash
extension=$1
path=$2
for file in "$path"/*.$extension; do
    mv -- "$file" "${file%%.$extension}"
done
