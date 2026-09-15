import time
start_time = time.time()

N = 1_000_000

proper_divisor_sums = [1] * (N + 1)
visited = [False] * (N + 1)

for i in range(2, N + 1):
    for j in range(i * 2, N + 1, i):
        proper_divisor_sums[j] += i

for num in range(2, N + 1):
    if not visited[num]:
        chain = [num]
        current = num
        while proper_divisor_sums[current] not in chain:
            current = proper_divisor_sums[current]
            chain.append(current)
            if current > N or visited[current]:
                break

        if current < N and proper_divisor_sums[current] in chain and len(chain) > 2:
            chain = chain[chain.index(proper_divisor_sums[current]):]
            if len(chain) > 2:
                print(chain)
        for c in chain:
            if c < N:
                visited[c] = True

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")