#!/usr/bin/env bash

if [ $# -ne 1 ]; then
	echo "Usage: $0 <file>"
	exit 1
fi

file_name="$1"

if [ ! -f "$file_name" ]; then
	echo "File '$file_name' does not exist"
	exit 1
fi

# Define the factor function
factorize()
{
	local num=$(echo "$1" | tr -d ':')
	local fact="$2"
	local prime=$(echo "$num / $fact" | bc)
	echo "$num=$prime*$fact"
}

while IFS= read -r line; do
	result=$(factor $line)
	factorize $result
done < "$file_name"
