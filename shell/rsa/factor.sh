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
	isprime=1
	local num=$1
	local root=$(echo "sqrt($num) + 1" | bc)
	if [ $num -eq 2 ]; then
		return $isprime
	fi
	for ((number = 2; number <= root; number++)); do
		if [ $(echo "$num % $number" | bc) -eq 0 ]; then
			isprime=0
			return $isprime
		fi
	done
	return $isprime
}


# Define the factor function
factorize()
{
	local num=$(echo "$1" | tr -d ':')
	local index=2
	for ((i = index; i < $#; i++)); do
		check_prime ${!i}
		value=$?
		if [ $value -eq 1 ]; then
			echo "${!i}"
			prime=$(echo "$num / ${!i}" | bc)
			check_prime $prime
			prime_true=$?
			if [ $prime_true -eq 1 ]; then

				echo "$num=$prime*${!i}"
				return;
			fi
		fi
	done
	echo "No primes"
}

while IFS= read -r line; do
	result=$(factor $line)
	factorize $result
done < "$file_name"
