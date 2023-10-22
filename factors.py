#!/usr/bin/python3
import sys
import math
import ctypes
import os

if "LD_LIBRARY_PATH" not in os.environ:
  os.environ["LD_LIBRARY_PATH"] = os.environ["PWD"]

def is_factor(num, factor):
    if (num % factor == 0):
        return True
    return False

def is_prime(num):
    for i in range(2, (num // 2) + 2):
        if is_factor(num, i):
            return False
    return True

# Define a function to check a number and return its factor pair
def check_number(n):
    if n <= 18446744073709551615:
        factor_pair = get_factor_pair_function(ctypes.c_ulonglong(n))
        return
    else:
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                print(f"{n}={i}*{n//i}")
                return


if len(sys.argv) != 2:
    print("Usage: factor <file>")
    sys.exit(1)

file_name = sys.argv[1]

os.environ["LD_LIBRARY_PATH"] += ":" + "."
lib = ctypes.CDLL('my_library.so')

get_factor_pair_function = lib.get_factor_pair

try:
    with open(file_name, 'r') as file:
        numbers = []
        for line in file:
            line = line.strip()
            if not line:
                continue  # Skip empty lines
            try:
                number = int(line)
                numbers.append(number)
            except ValueError:
                print(f"Skipping invalid line: {line}")

    for number in numbers:
       check_number(number)

except FileNotFoundError:
    print(f"{file_name} not found")
