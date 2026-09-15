from math import sqrt
import time
from functions import is_prime
from collections import Counter

def are_permutations(num1, num2):
    return Counter(str(num1)) == Counter(str(num2))

start_time = time.time()


def compute_totients(n, prime):
    phi = list(range(n+1))
    for i in range(2, n+1):
        if prime[i]:
            for j in range(i, n+1, i):
                phi[j] *= (1- 1/i)
    return phi



n = 10000000
primeBool = is_prime(n)
primes = [num for num in range(n+1) if primeBool[num]]

multiple_list = []

smallestN = -1
smallestRatio = 2

for num, val in enumerate(compute_totients(n, primeBool)):
    val = int(val)
    if val > 0 and num > 1 and num / val < smallestRatio:
        if are_permutations(num, val):
            smallestN = num
            smallestRatio = num / val

print(smallestN, smallestRatio)



end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")