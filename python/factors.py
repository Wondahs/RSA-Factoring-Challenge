#!/usr/bin/python3
import sys

def is_factor(num, factor):
    if (num % factor == 0):
        return True
    return False

def is_prime(num):
    for i in range(2, (num // 2) + 2):
        if is_factor(num, i):
            return False
    return True

if len(sys.argv) != 2:
    print("Usage: factor <file>")
    sys.exit(1)

file_name = sys.argv[1]

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
        if is_prime(number):
            continue
        for j in range(2, (number // 2) + 2):
            if is_factor(number, j):
                print(f"{number}={j}*{number // j}")
                break

except FileNotFoundError:
    print(f"{file_name} not found")
