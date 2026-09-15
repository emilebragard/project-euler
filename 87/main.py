from functions import gen_primes
from math import sqrt
import time

start_time = time.time()

seen_nums = {}

n = 50_000_000
primes = gen_primes(int(sqrt(n)))

for a in primes:
    num1 = a**4
    if num1 > n:
        break
    for b in primes:
        num2 = b**3
        if num1 + num2 > n:
            break
        for c in primes:
            final_num = num1 + num2 + c**2
            if final_num < n:
                seen_nums[final_num] = True

print(len(seen_nums))

print("elapsed time: ", time.time() - start_time, " seconds")