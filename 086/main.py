import time
from math import sqrt, gcd

start_time = time.time()

L = 100_000
maxA =  int(L / 2)

squared = [x**2 for x in range(0, maxA + 2)]
integer_right_triangles = [[] for _ in range(50_000)]

for m in range(1, int(2*sqrt(L))):
    for n in range(m % 2 + 1, m, 2):
        if gcd(m,n) == 1:
            a = squared[m] - squared[n]
            b = 2 * m * n
            c = squared[m] + squared[n]
            length = a + b + c
            i = 1
            B = b
            while length < L/4:
                A = a*i
                C = c*i
                length = A + B + C
                integer_right_triangles[A].append(B)
                integer_right_triangles[B].append(A)
                i+=1
                B = b*i

count = 0    
M = 1
while count < 1_000_000:
    M += 1
    for bc_val in integer_right_triangles[M]:
        if bc_val // 2 <= M:
            if bc_val <= M:
                count += bc_val // 2
            else:
                count += abs(M - ((bc_val + 1) // 2)) + 1

print(f"M = {M}, count = {count}")       


end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")