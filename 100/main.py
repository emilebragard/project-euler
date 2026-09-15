import time
from math import sqrt, ceil

start_time = time.time()

prob_ratio = sqrt(2)/2.0

min_desired = 10 ** 12
current = 20
last_denom = 21 / 5

while current:
    upper = ceil(current*prob_ratio)
    lower = upper - 1
    if (lower * upper * 2 == current * (current-1)):
        inc_ratio = current / last_denom
        last_denom = current
        if current > min_desired:
            print(f"Found solution: {upper}/{current} * {lower}/{current-1} = 1/2")
            print("Blue disks: ", upper)
            break
        current = int(current * inc_ratio)
    else:
        current += 1

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")