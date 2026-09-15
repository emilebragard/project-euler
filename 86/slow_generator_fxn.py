import time
from functions import perf_square_bool
from math import sqrt, gcd, floor
from itertools import combinations_with_replacement

start_time = time.time()

M = 20
L = 7*M
maxA =  int(L / 2)

squared = [x**2 for x in range(0, maxA + 2)]
integer_right_triangles = {}


for m in range(1, int(2*sqrt(L))):
    for n in range(m % 2 + 1, m, 2):
        if gcd(m,n) == 1:
            a = squared[m] - squared[n]
            b = 2 * m * n
            c = squared[m] + squared[n]
            if b < a:
                b = squared[m] - squared[n]
                a = 2 * m * n
            length = a + b + c
            i = 1
            B = b
            while B < 2*M:
                A = a*i
                C = c*i
                length = A + B + C
                integer_right_triangles[(A, B)] = True
                i+=1
                B = b*i

        

# for irt in integer_right_triangles:
#     print(irt)

count = 0

for x in range(1, M+1):
    for y in range(1, x+1):
        for z in range(1, min(x,y+1)):
            A = y + z
            B = x
            if A > B:
                B = y + z
                A = x
            if (A, B) in integer_right_triangles and integer_right_triangles[(A, B)]:
                print(x,y,z)
                count += 1
            

print(count)

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")