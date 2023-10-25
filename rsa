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
	if [ $# -eq 3 ]; then
		fact=$2
		prime=$3
		echo "$num=$fact*$prime"
	else
		echo "No primes"
	fi
}

while IFS= read -r line; do
	result=$(factor $line)
	factorize $result
done < "$file_name"
