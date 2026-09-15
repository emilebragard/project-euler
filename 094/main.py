import time
from functions import gen_primes
from math import isqrt, floor
start_time = time.time()

xlist = []

for x in range(5, 333_333_334, 4):
    val = (3*x + 1) * (x - 1)
    s = isqrt(val)
    if s * s == val:
        print(x, x, x+1, ((x+1) * s))
        xlist= xlist +[x, x, x+1]

for x in range(17, 333_333_334, 4):
    val = (3*x - 1) * (x + 1)
    s = isqrt(val)
    if s * s == val:
        print(x, x, x-1, ((x-1) * s))
        xlist= xlist +[x, x, x-1]

print(sum(xlist))

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")