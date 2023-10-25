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

# Check if num is prime
check_prime()
{
	local num=$1
	local root=$(echo "sqrt($num) + 1" | bc)
	for number in {2..$root}; do
		if [ ! $(echo "$num % $number" | bc) ]; then
			return 1
		fi
	done
	return 0
}


# Define the factor function
factorize()
{
	local num=$(echo "$1" | tr -d ':')
	local index=0
	for ((i = index; i < $($[@]); i++)); do
		if [ ! check_prime $($[$i]) ]; do
			prime=$(echo "$num / $($[$i])" | bc)
			if [ ! check_prime $prime]; do

				echo "$num=$prime*$($[$i])"
				return;
			fi
		fi
	done
}

while IFS= read -r line; do
	result=$(factor $line)
	factorize $result
done < "$file_name"
