import time
from functions import is_prime

start_time = time.time()

n = 100
primeBool = is_prime(n)
primes = [num for num in range(n+1) if primeBool[num]]

curNum = 1
primeIdx = 0

while curNum*primes[primeIdx] <= 1000000:
    curNum *=primes[primeIdx]
    primeIdx+=1

print(curNum)

end_time = time.time()


print("elapsed time: ", end_time - start_time, " seconds")