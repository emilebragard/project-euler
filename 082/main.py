import time

start_time = time.time()

with open("0082_matrix.txt") as file:
    lines = file.readlines()

matrix = []
for line in lines:
    line = line.strip()
    row_vals = line.split(',')
    row_ints = list(map(int, row_vals))
    matrix.append(row_ints)

length = len(matrix)-1
visited =[]

options = []
for num in range(0,length+1):
    options.append([[num,0], matrix[num][0]])
options.sort(key=lambda x: x[1])

while options[0][0][1] != length:
    # Pop the best option
    current = options[0]
    x, y = current[0]
    val = current[1]
    options.pop(0)

    if [x,y] not in visited:
        visited.append([x,y])
        #Right
        if y < length:
            options.append([[x, y+1], val + matrix[x][y+1]])
        #Down
        if x < length:
            options.append([[x+1, y], val + matrix[x+1][y]])
        #Up
        if x > 0:
            options.append([[x-1, y], val + matrix[x-1][y]])
    else:
        for idx, option in enumerate(options):
            if option[0] == (x,y):
                if val < option[1]:
                    option[1] = val

    options.sort(key=lambda x: x[1])

# Answer
print(options[0][1])

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")