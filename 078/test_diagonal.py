N = 300

P = [[0], [0, 1], [0,1,2], [0,1,2,3], [0,1,3,4,5]]

while len(P) <= N:
    n = len(P)
    row = [0, 1, n//2+1]
    for k in range(3, n):
        row.append(P[n-k][min(k,n-k)] + row[-1])
    row.append(row[-1]+1)
    P.append(row)

# diagonal: Q[n][n-2] = P[n][n-2] - P[n][n-3] for n >= 3
diagonal = [(n, P[n][n-2] - P[n][n-3]) for n in range(3, N+1)]

# find first repetition (consecutive equal values)
repeat_start_idx = None
for i in range(1, len(diagonal)):
    if diagonal[i][1] == diagonal[i-1][1]:
        repeat_start_idx = i
        break

if repeat_start_idx is None:
    print("No repetition found through N={N}")
else:
    n_rep, val_rep = diagonal[repeat_start_idx]
    max_before = max(v for _, v in diagonal[:repeat_start_idx])
    print(f"First repetition at n={n_rep}, value={val_rep}")
    print(f"Max value before repetition: {max_before}")
    print()

    violations = [
        (n, val) for n, val in diagonal[repeat_start_idx:]
        if val > max_before
    ]

    if violations:
        print(f"HYPOTHESIS VIOLATED — {len(violations)} case(s) where value increased after repetition:")
        for n, val in violations:
            print(f"  n={n}: Q[n][n-2] = {val}")
    else:
        print("Hypothesis holds through N=300: no value increased after repetition began.")

print()
print("Full diagonal (n, Q[n][n-2]):")
for n, val in diagonal:
    print(f"  n={n:3d}  Q={val}")
