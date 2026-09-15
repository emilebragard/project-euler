import time
from itertools import combinations
start_time = time.time()

possibilities = list(combinations(range(10), 6))

valid = set()

for i, list1 in enumerate(possibilities):
    for list2 in possibilities[i:]:
        needed_nums = {0, 1, 2, 3, 4, 5, 8}
        if not needed_nums.issubset(list1 + list2):
            continue
        if not ((0 in list1 and 9 in list2) or (0 in list2 and 9 in list1) or (0 in list1 and 6 in list2) or (0 in list2 and 6 in list1)):
            continue
        if not ((0 in list1 and 4 in list2) or (0 in list2 and 4 in list1)):
            continue
        if not ((0 in list1 and 1 in list2) or (0 in list2 and 1 in list1)):
            continue 
        if not ((2 in list1 and 5 in list2) or (2 in list2 and 5 in list1)):
            continue       
        if not ((4 in list1 and 9 in list2) or (4 in list2 and 9 in list1) or (4 in list1 and 6 in list2) or (4 in list2 and 6 in list1)):
            continue 
        if not ((6 in list1 and 1 in list2) or (6 in list2 and 1 in list1) or (9 in list1 and 1 in list2) or (9 in list2 and 1 in list1)):
            continue 
        if not ((8 in list1 and 1 in list2) or (8 in list2 and 1 in list1)):
            continue 
        if not ((6 in list1 and 3 in list2) or (6 in list2 and 3 in list1) or (9 in list1 and 3 in list2) or (9 in list2 and 3 in list1)):
            continue 

        valid.add(tuple(sorted((list1, list2))))

# for lists in valid:
#     print(lists)

print("Answer is ", len(valid))
end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")