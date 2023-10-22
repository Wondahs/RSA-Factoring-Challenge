#!/usr/bin/python3

import ctypes

# Load the shared library
lib = ctypes.CDLL('my_library.so')

# Get a pointer to the C function
get_factor_pair_function = lib.get_factor_pair

# Define a function to check a number and return its factor pair
def check_number(n):
    if n <= (18446744073709551615):
        # The number is less than unsigned long long max, so use the C function
        factor_pair = get_factor_pair_function(ctypes.c_ulonglong(n))

    else:
    # The number is greater than unsigned long long max, so use Python
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                print(f"{n}={i}*{n/i}")


# Get the range of numbers to check
start_number = 1000
end_number = 20006278

# Check each number in the range and print its factor pair
for i in range(start_number, end_number + 1):
    factor_pair = check_number(i)
