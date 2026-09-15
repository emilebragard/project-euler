
import math

def generate_primes(n):
    is_prime = [True] * (n+1)
    is_prime[0] = is_prime[1] = False
    prime_list = []

    for i in range(2, int(math.sqrt(n)) + 1):
        if is_prime[i]:
            prime_list.append(i)
            for j in range(i * i, n + 1, i):
                is_prime[j] = False

    for i in range(int(math.sqrt(n)) + 1, n + 1):
        if is_prime[i]:
            prime_list.append(i)

    return prime_list, is_prime
