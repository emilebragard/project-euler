import time
import numpy as np
import pandas as pd
from collections import deque

start_time = time.time()

goal_div = 1_000_0

# P[n][k] is equal to the number of ways to seperate n coins into piles of at most k coins
P = [[0], [0, 1], [0,1,2], [0,1,2,3], [0,1,3,4,5]]
part_nums = [row[-1] % goal_div for row in P]

while (P[-1][-1] != 0):
    n = len(P)
    row = [0, 1, (n//2+1) % goal_div]
    for k in range(3, n//2 + 1):
        row.append((P[n-k][k] + row[-1]) % goal_div)
    for k in range(n//2 + 1, n):
        row.append((part_nums[n-k] + row[-1]) % goal_div)
    row.append((row[-1] + 1) % goal_div)
    P.append(row)
    part_nums.append(row[-1])

# for row in P:
#     print(row)

print(f"FOUND: P({n}) = {P[-1][-1]}")

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")