import time
from functions import gen_primes

start_time = time.time()

cur = 1

for num in range(7830457):
    cur = cur * 2 % 10**10

cur = cur * 28433 % 10**10 + 1
print(cur)

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")