#!/usr/bin/python3

import sympy

# Function to perform the elliptic curve addition operation
def ec_add(P, Q, a, N):
    if P == Q:
        m = (3 * P[0] ** 2 + a) * sympy.mod_inverse(2 * P[1], N)
    else:
        m = (Q[1] - P[1]) * sympy.mod_inverse(Q[0] - P[0], N)
    x = (m ** 2 - P[0] - Q[0]) % N
    y = (m * (P[0] - x) - P[1]) % N
    return (x, y)

# Function to perform the elliptic curve multiplication operation
def ec_multiply(P, n, a, N):
    Q = (None, None)
    for bit in bin(n)[2:]:
        Q = ec_add(Q, Q, a, N)
        if bit == '1':
            Q = ec_add(P, Q, a, N)
    return Q

# ECM (Elliptic Curve Method) for integer factorization
def ecm_factorization(N, B1, B2):
    a = 2  # Coefficient in the elliptic curve equation: y^2 = x^3 + a*x + b
    x = sympy.randprime(1, N - 1)
    P = (x, 1)
    d = sympy.gcd(N, 4 * a ** 3)

    if d > 1:
        return d  # N is a multiple of d

    for k in range(1, B1 + 1):
        P = ec_multiply(P, k, a, N)
        d = sympy.gcd(N, P[0] - x)
        if d > 1:
            return d  # A non-trivial factor has been found

    return None  # No factor found within B1

# Function to factorize a number using ECM and return the formatted string
def factorize_and_format(N, B1, B2):
    factor = ecm_factorization(N, B1, B2)
    if factor is not None:
        return f"{N}={factor}*{N//factor}"
    else:
        return f"No non-trivial factor found within B1 = {B1}"

# Main program to read numbers from a file and factorize
if __name__ == "__main__":
    input_filename = "numbers.txt"  # Replace with the name of your input file
    B1 = 10  # First stage bound
    B2 = 100  # Second stage bound

    with open(input_filename, "r") as file:
        for line in file:
            N = int(line.strip())
            result = factorize_and_format(N, B1, B2)
            print(result)
