import time
from math import gcd
from functions import is_prime

start_time = time.time()

def larger_frac(pair1, pair2):
    if pair1[0]*pair2[1] == pair1[1]*pair2[0]:
        return "same"
    elif pair1[0]*pair2[1] > pair1[1]*pair2[0]:
        return pair1
    else:
        return pair2

n = 12_000

fracs = 0

bottom = (1,3)
top = (1,2)

for denom in range(2,n+1):
    for num in range(denom * bottom[0] // bottom[1], ((denom * top[0]) + 1) // top[1]):
        curFrac = (num, denom)
        if gcd(num,denom) == 1:
            # print(curFrac, larger_frac(curFrac,bottom), larger_frac(curFrac, top))
            if larger_frac(curFrac,bottom) == curFrac and larger_frac(curFrac, top) == top:
                fracs+=1

print(fracs)

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")