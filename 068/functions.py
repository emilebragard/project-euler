from math import sqrt


def cont_frac_calc(list):
    num_list = list[:]
    current = (0,1)
    while len(num_list) > 0:
        new = current[1]*num_list[-1] + current[0]
        num_list.pop()
        current = (current[1], new)
        if len(num_list) == 0:
            current = (current[1], current[0])
    return current

def cont_frac_sqrt(n):
    first = int(sqrt(n))
    if first ** 2 == n:
        return 0, []
    m = 0
    d = 1
    a = first
    period = []
    while a != 2*first:
        m = d*a - m
        d = (n - m**2) / d
        a = int((first + m) / d)
        period.append(a)
    return first, period
    
def gen_primes(n):
    is_prime = [True] * (n+1)
    is_prime[0] = is_prime[1] = False
    prime_list = []

    for i in range(2, int(sqrt(n)) + 1):
        if is_prime[i]:
            prime_list.append(i)
            for j in range(i * i, n + 1, i):
                is_prime[j] = False

    for i in range(int(sqrt(n)) + 1, n + 1):
        if is_prime[i]:
            prime_list.append(i)

    return prime_list

def gen_triangular(triangular_nums):
    n = len(triangular_nums) + 1
    triangular_nums.append(int((n * (n + 1)) / 2))

def gen_square(square_nums):
    n = len(square_nums) + 1
    square_nums.append(int((n ** 2)))

def gen_pentagonal(pentagonal_nums): 
    n = len(pentagonal_nums) + 1
    pentagonal_nums.append(int(n * (3*n - 1) / 2)) 

def gen_hexagonal(hexagonal_nums): 
    n = len(hexagonal_nums) + 1
    hexagonal_nums.append(int(n * (2*n - 1)))

def gen_heptagonal(heptagonal_nums):
    n = len(heptagonal_nums) + 1
    heptagonal_nums.append(int((n * (5*n - 3)) / 2))

def gen_octagonal(octagonal_nums):
    n = len(octagonal_nums) + 1
    octagonal_nums.append(int((n * (3*n - 2))))

