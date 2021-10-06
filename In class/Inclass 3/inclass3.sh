cd breakfast
#!/bin/bash
check=messy/file3.txt
if test -f "$check"; then
    echo "$check exists."
    sed G $check
else
    echo "$check does not exist."
fi
for stuff in *
do
		if [ -f $stuff ]
		then
				echo $stuff
		fi
done
for things in *
do
		if [ -f $things ]
		then    sudo find "$(pwd)" -name "$things"
				find . -name "$things" -exec ls -lh {} \;
		fi
done
ls ~/*.txt
