import time

start_time = time.time()

with open("0089_roman.txt", "r") as keys:
    lines = keys.readlines()

count = 0

for num in lines:
    if "IIII" in num:
        count += 2
        if "VIIII" in num:
            count += 1
    if "XXXX" in num:
        count += 2
        if "LXXXX" in num:
            count += 1
    if "CCCC" in num:
        count += 2
        if "DCCCC" in num:
            count += 1

print(count)

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")