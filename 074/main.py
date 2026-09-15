import time
from math import factorial
from itertools import combinations_with_replacement

start_time = time.time()

factorial_digs = [factorial(n) for n in range(0,10)]

factorial_dig_sum = {}
loop_length_map = [None for num in range(1, factorial_digs[9] * 7)]

for digs in range(1,8):
    combs = combinations_with_replacement(range(10), digs)
    for comb in combs:
        total = 0
        for item in comb:
            total += factorial_digs[item]
        factorial_dig_sum[comb] = total

for startingNum in range(1, 10**6):
    current = startingNum
    sequence = []

    while current not in sequence and loop_length_map[current] == None:
        digits = [int(digit) for digit in str(current)]
        digits.sort()
        digits = tuple(digits)
        nextNum = factorial_dig_sum[digits]
        sequence.append(current)
        current = nextNum
    
    bonus = 0
    
    if loop_length_map[current] != None:
        bonus = loop_length_map[current]
        for idx, num in enumerate(sequence):
            loop_length_map[num] = len(sequence) - idx + bonus
    
    else:
        loop_length = len(sequence) - sequence.index(current)
        loop_start = len(sequence) - loop_length
        # print(sequence, loop_length)
        for idx, num in enumerate(sequence):
            if idx < loop_start:
                loop_length_map[num] = len(sequence) - idx
            else:
                loop_length_map[num] = loop_length
    # if loop_length_map[startingNum] == 60:
    #     print(startingNum, sequence, loop_length_map[startingNum])


exactly60 = 0
for idx, num in enumerate(loop_length_map):
    if num == 60:
        exactly60+=1
print(exactly60)

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")