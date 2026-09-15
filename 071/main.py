from math import floor
import time
from functions import is_prime

start_time = time.time()

def larger_frac(pair1, pair2):
    if pair1[0]*pair2[1] > pair1[1]*pair2[0]:
        return pair1
    else:
        return pair2
    
def compute_facs(n, prime):
    facs = [{1} for n in range(n+1)]
    for i in range(2, n+1):
        if prime[i]:
            for j in range(i, n+1, i):
                facs[j].add(i)
    return facs

n = 1000000
primeBool = is_prime(n)

primeFacs = compute_facs(n,primeBool)

fracs = []

desired = (3,7)
closest = (1, 8)

for denom in range(2,n+1):
    for num in range(floor((desired[0]/desired[1])*denom),denom):
        curFrac = (num, denom)
        if larger_frac(curFrac,closest) == curFrac:
            if primeFacs[num].intersection(primeFacs[denom]) == {1}:
                if larger_frac(curFrac, desired) == desired and curFrac != (3,7):
                    closest = curFrac
            break

print(closest)

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")