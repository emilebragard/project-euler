import time
from functions import gen_primes, is_prime
import numpy as np

start_time = time.time()

N = 10_000
primes = gen_primes(N+1)
isPrime = is_prime(N+1)

matrix = np.zeros((N+1,N+1))

# Initialize first col
for row in range(4, N+1, 2):
    matrix[row, 2] = 1

found = False
# Use solved fxn to fill each row
for n in range(5, N+1):
    if found: 
        break
    for x in primes[1:]:
        if x < n:
            sumCounts = sum(matrix[n - x][:x+1])
            if x >= n-x and isPrime[n-x]:
                sumCounts+=1
            matrix[n, x] = sumCounts
        else: 
            if int(sum(matrix[n])) > 5000:
                print(n, int(sum(matrix[n])))
                found = True

            break



end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")