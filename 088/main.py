from math import sqrt
import time

start_time = time.time()


def gen_factors(n):
    facs = [set() for _ in range(n+1)]

    for i in range(2, int(sqrt(n)) + 1):
        for j in range(i * 2, n + 1, i):

            num1 = min(i, j//i)
            num2 = max(j//i, i)
            first_sum = num1 + num2
            
            facs[j].add((first_sum, (num1, num2)))

            for group in facs[num2]:
                new_sum = sum(group[1]) + num1
                facs[j].add((new_sum, tuple(sorted((group[1] + (num1,))))))

    for idx, fac in enumerate(facs):
        facs[idx] = sorted(fac, key=lambda x: x[0])
    return facs


N = 13_000
factors = gen_factors(N)

K = 12_000

minimal_product_sum = []

for k in range(2,K+1):
    found = False
    current = k 
    while not found and current < len(factors):
        cur_factors = factors[current]
        for sum_val, group in cur_factors:
            if sum_val > current:
                break
            if len(group) + current - sum_val == k:
                minimal_product_sum.append(current)
                found = True
                break
        current += 1

print(f"K = {K}, found {len(minimal_product_sum)} / {K-1} minimal product sums")
print(f"Sum is {sum(set(minimal_product_sum))}")

print("elapsed time: ", time.time() - start_time, " seconds")