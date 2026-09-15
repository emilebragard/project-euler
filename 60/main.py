from functions import generate_primes

def conc(num1, num2):
    return num1 * (10 ** len(str(num2))) + num2

def all_conc(numlist, is_prime):
    for num1 in numlist:
        for num2 in numlist:
            if num1 != num2:
                if not is_prime[conc(num1, num2)]:
                    return False
    return True

primes, is_prime = generate_primes(10 ** 8)
print("Primes calculated.")

found = False
cur = 0
concd_prime = []

while not found and cur < len(primes):
    # Append a new row for the current prime
    concd_prime.append([is_prime[conc(primes[cur], primes[a])] for a in range(cur)] + [True])
    # Update existing rows with the new prime
    for a in range(cur):
        concd_prime[a].append(is_prime[conc(primes[a], primes[cur])])
    
    for i in range(cur):
        if concd_prime[cur][i] and concd_prime[i][cur]:
            for j in range(i + 1, cur):
                if concd_prime[cur][j] and concd_prime[j][cur] and concd_prime[i][j] and concd_prime[j][i]:
                    for k in range(j + 1, cur):
                        if concd_prime[cur][k] and concd_prime[k][cur] and concd_prime[i][k] and concd_prime[k][i] and concd_prime[j][k] and concd_prime[k][j]:
                            for l in range(k+1, cur):
                                if concd_prime[cur][l] and concd_prime[l][cur] and concd_prime[i][l] and concd_prime[l][i] and concd_prime[j][l] and concd_prime[l][j] and concd_prime[l][k] and concd_prime[k][l]:
                                    print(f"Found primes: {primes[i]}, {primes[j]}, {primes[k]}, {primes[l]}, {primes[cur]}. Sum = {primes[l]+primes[i]+primes[j]+primes[k]+primes[cur]}")
                                    found = True
                                    break
                        if found:
                            break
                if found:
                    break
        if found:
            break
    cur += 1
