
import time



start_time = time.time()

def first_exp_greater(num1, num2):
    b1, e1 = num1
    b2, e2 = num2
    # print(b1, e1, b2, e2)
    while (e1 > 1 or e2 > 1) and (b1 > 1) and (b2 > 1):
        if e1 > e2:
            e1 = e1 - e2
            b2 = (b2 / b1) * 1.0
            
        else:
            e2 = e2 - e1
            b1 = (b1 / b2) * 1.0
    #     print(b1, e1, b2, e2)
    # print()
    # print()
    if b1 < 1:
        return False
    if b2 < 1:
        return True
    return b1 > b2

pairs = []

with open("0099_base_exp.txt", "r+") as f:
    linereader = f.readlines

    for line in f:
        num1, num2 = line.strip().split(',')
        pairs.append((int(num1), int(num2)))

max_pair = pairs[0]
max_idx = 0

for num in range(1, len(pairs)):
    if first_exp_greater(pairs[num], max_pair):
        max_pair = pairs[num]
        max_idx = num

print(f"Line number: {max_idx + 1}")

print("elapsed time: ", time.time() - start_time, " seconds")