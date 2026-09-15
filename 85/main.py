import time, random

start_time = time.time()

desired = 2_000_000

closest = 1_000_000
closest_size = None

natural_sums = [0]
while natural_sums[-1] < desired:
    natural_sums.append(natural_sums[-1]+len(natural_sums))

for length_idx, length in enumerate(natural_sums[1:]):
    last = None
    current = None
    width_idx = -1
    while True:
        width_idx+=1
        last = current
        current = length*natural_sums[width_idx]
        if length * natural_sums[width_idx] > desired:
            break
    
    if abs(desired-current) < closest:
        closest = abs(desired-current)
        closest_size = [length_idx+1, width_idx]

    if abs(desired-last) < closest:
        closest = abs(desired-last)
        closest_size = [length_idx+1, width_idx-1]
    

print(closest, closest_size, closest_size[0]*closest_size[1])

end_time = time.time()

print("\nelapsed time: ", end_time - start_time, " seconds")