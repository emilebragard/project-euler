import time
import numpy as np

start_time = time.time()

N = 100
matrix = np.zeros((N+1,N+1))

# Initialize first col
for row in range(2, N+1):
    matrix[row, 1] = 1

# Use solved fxn to fill each row
for n in range(3, N+1):
    for x in range(2, n):
        sumCounts = sum(matrix[n - x][:x+1])
        if x >= n-x:
            sumCounts+=1
        matrix[n,x] = sumCounts

print(int(sum(matrix[N])))

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")