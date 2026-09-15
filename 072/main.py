import time
from functions import is_prime

start_time = time.time()
    
def compute_totients(n, prime):
    phi = list(range(n+1))
    phi[1] = 0
    for i in range(2, n+1):
        if prime[i]:
            for j in range(i, n+1, i):
                phi[j] *= (1- 1/i)
                # print(i, j)
    return phi

n = 1_000_000
primeBool = is_prime(n)

totients = compute_totients(n,primeBool)
print(int(sum(totients)))

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")