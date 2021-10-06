#!/bin/bash
#download data from wiki
content=$(curl -L https://en.wikipedia.org/wiki/World_Happiness_Report?action=raw) 
#find line numbers for start and end
rep=$(echo "$content" | grep -n '| 1||{{flag|Finland}}||7.632||1.305||1.592||0.874||0.681||0.202||0.393')
test_line=$(echo "$content" | grep -n '| 10||{{flag|Australia}}||7.272||1.340||1.573||0.910||0.647||0.361||0.302')
#extract line numbers for start and end
end_line=$(echo "$test_line" | cut -d ':' -f 1)
h=$(echo "$rep" | cut -d ':' -f 1)
start=$(($h-14))
#Get data from the required lines
tst=$(echo "$content" | sed -n "$start,$end_line p")
#Extract by field
chal=$(echo "$tst" | cut -d '|' -f 5)
#Remove empty lines
lines=$(echo "$chal" | sed '/^\s*$/d')
#Extract only names of countries
output=$(echo "$lines" | while read line; do sed 's/}//g';done)
echo "$output"  

