#!/bin/bash
current=$(date +%F | cut -d "-" -f 1)
for line in $(cat "$1"); 
do
	name=$(echo $line | cut -d "," -f 1)
	l_name=$(echo $line | cut -d "," -f 2)
	year=$(echo $line | cut -d "," -f 3 | cut -b 1-4 )
	age=$(($current-$year))
	if ((age<0)); then
		new=$(($current+543))
		new_age=$(($new-$year))
		if ((new_age>=18)); then
			echo 'Dear Mr/Mrs' "$l_name"',' "$name"
		fi
	elif ((age>=18)); then 
		echo 'Dear Mr/Mrs' "$l_name"',' "$name"
	fi
done

