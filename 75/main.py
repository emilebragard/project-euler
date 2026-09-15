import time
from functions import perf_square_bool
from math import sqrt, gcd, floor
from itertools import combinations_with_replacement

start_time = time.time()

L = 1_500_000
maxA =  int(L / 2)

squared = [x**2 for x in range(0, maxA + 2)]
sqaure_set = {x**2 for x in range(0, maxA + 2)}
integer_sided_right_angles = [0 for _ in range(L+1)]

for m in range(1, int(sqrt(L/2))):
    for n in range(m % 2 + 1, m, 2):
        if gcd(m,n) == 1:
            a = squared[m] - squared[n]
            b = 2 * m * n
            c = squared[m] + squared[n]
            length = a + b + c
            if length < L:
                for multLen in range(length, L, length):
                    integer_sided_right_angles[multLen] += 1

exactly1 = 0     
for idx, num in enumerate(integer_sided_right_angles):
    if num == 1:
        exactly1+=1
print(exactly1)

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")