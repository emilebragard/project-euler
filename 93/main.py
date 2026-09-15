import time
from itertools import combinations, permutations, product
import operator

start_time = time.time()

attainable_sets = [set() for _ in range(10_000)]

op_funcs = [
    operator.add,
    operator.sub,
    operator.mul,
    lambda x, y: x/y if y else None
]

patterns = [
    lambda a,b,c,d,f1,f2,f3: f3(f2(f1(a,b),   c), d),
    lambda a,b,c,d,f1,f2,f3: f3(f1(a, f2(b,c)), d),
    lambda a,b,c,d,f1,f2,f3: f1(a, f3(f2(b,c),   d)),
    lambda a,b,c,d,f1,f2,f3: f1(a, f2(b, f3(c,d))),
    lambda a,b,c,d,f1,f2,f3: f2(f1(a,b),     f3(c,d)),
]

ops = range(4)

for combo in combinations(range(10), 4):
    key    = int(''.join(map(str, combo)))
    bucket = attainable_sets[key]

    for a,b,c,d in permutations(combo):
        for i1,i2,i3 in product(ops, repeat=3):
            f1, f2, f3 = op_funcs[i1], op_funcs[i2], op_funcs[i3]

            for pat in patterns:
                try:
                    v = pat(a, b, c, d, f1, f2, f3)
                except TypeError:
                    continue

                if v is None:
                    continue

                if v > 0 and abs(v - int(v)) < 1e-9:
                    bucket.add(int(v))

attainable_lists = [sorted(s) for s in attainable_sets]

max_consec = 0
max_key   = None
for key, vals in enumerate(attainable_lists):
    run = 0
    while run+1 in vals:
        run += 1
    if run > max_consec:
        max_consec, max_key = run, key

print(f"Max consecutive: {max_consec} from digits {max_key}")
print("Elapsed:", time.time() - start_time, "s")
