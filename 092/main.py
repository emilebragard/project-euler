import time
from functions import num_to_digits

start_time = time.time()

squared = [x**2 for x in range(0, 10)]

N = 10_000_000

squared_dig_sum = {}
loop_map = [None for num in range(0, 81*7+1)]
loop_map[1] = 1
loop_map[89] = 89

count89 = 0

for startingNum in range(1, 81*7+1):
    current = startingNum
    sequence = []

    while current > 81*7 or loop_map[current] == None:
        nextNum = 0
        for dig in num_to_digits(current):
            nextNum+=squared[dig]
        sequence.append(current)
        current = nextNum
    
    end_num = loop_map[current]
    for num in sequence:
        loop_map[num] = end_num


for num in range(1, 10_000_000):
    digitSum = 0
    for dig in num_to_digits(num):
        digitSum+=squared[dig]

    if loop_map[digitSum] == 89:
        count89+=1

print(count89)

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")