import time
from math import sqrt
start_time = time.time()

N = 50
count = 0

for x1 in range(N+1):
    for y1 in range(N+1):
        if x1 == 0 and y1 == 0:
            continue
        for x2 in range(N+1):
            for y2 in range(N+1):
                if (x1 == x2 and y1 == y2) or (x2 == 0 and y2 == 0) or (x1,y1) > (x2, y2):
                    continue
                line1_sq = x1 * x1 + y1 * y1
                line2_sq = x2 * x2 + y2 * y2
                line3_sq = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)
                lines_sq = sorted([line1_sq, line2_sq, line3_sq])
                if lines_sq[0] + lines_sq[1] == lines_sq[2]:
                    count += 1

print(count)

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")