import time


start_time = time.time()

# Found by hand answer
pot = [7,3,1,6,2,8,9,0]

with open("0079_keylog.txt", "r") as keys:
    lines = keys.readlines()

correct = True

for line in lines:
    num1 = int(line[0])
    num2 = int(line[1])
    num3 = int(line[2])

    if not (pot.index(num1) <pot.index(num2) and pot.index(num2) < pot.index(num3)):
        correct = False

if correct:
    print(pot)

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")