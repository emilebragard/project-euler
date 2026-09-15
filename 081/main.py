import time

start_time = time.time()

with open("0081_matrix.txt") as file:
    lines = file.readlines()

matrix = []
for line in lines:
    line = line.strip()
    row_vals = line.split(',')
    row_ints = list(map(int, row_vals))
    matrix.append(row_ints)

length = len(matrix)-1
visited =[]

options = [((0,0), matrix[0][0])]
while options[0][0] != (length,length):
    # Pop the best option
    current = options[0]
    x, y = current[0]
    val = current[1]
    options.pop(0)

    if (x,y) not in visited:
        visited.append((x,y))
        #Right
        if y < length:
            options.append(((x, y+1), val + matrix[x][y+1]))
        #Down
        if x < length:
            options.append(((x+1, y), val + matrix[x+1][y]))

    options.sort(key=lambda x: x[1])

# Answer
print(options[0][1])

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")