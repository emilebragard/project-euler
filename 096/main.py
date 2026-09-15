import time
from functions import gen_primes
from math import isqrt, floor
start_time = time.time()

matrices = []

with open("p096_sudoku.txt", "r") as f:
    for line in f.readlines():
        if "Grid" in line:
            matrices.append([])
        else:
            matrices[-1].append(line.strip())

clean_matrices = []

for matrix in matrices:
    clean_matrices.append([])
    for i in range(9):
        clean_matrices[-1].append([])
        for j in range(9):
            num = matrix[i][j]
            clean_matrices[-1][-1].append(int(num))

def logical_steps(sudoku_matrix, possible_matrix):
    updated = False

    for i in range(9):
        for j in range(9):
            if sudoku_matrix[i][j] != 0:
                continue

            for poss in possible_matrix[i][j]:
                if all(
                    poss not in possible_matrix[i][k] or k == j
                    for k in range(9)
                ):
                    sudoku_matrix[i][j] = poss
                    possible_matrix[i][j] = []
                    possible_matrix = gen_possible(sudoku_matrix)
                    updated = True
                    break

                if all(
                    poss not in possible_matrix[k][j] or k == i
                    for k in range(9)
                ):
                    sudoku_matrix[i][j] = poss
                    possible_matrix[i][j] = []
                    possible_matrix = gen_possible(sudoku_matrix)
                    updated = True
                    break

                box_row = (i // 3) * 3
                box_col = (j // 3) * 3
                if all(
                    poss not in possible_matrix[bi][bj] or (bi == i and bj == j)
                    for bi in range(box_row, box_row + 3)
                    for bj in range(box_col, box_col + 3)
                ):
                    sudoku_matrix[i][j] = poss
                    possible_matrix[i][j] = []
                    possible_matrix = gen_possible(sudoku_matrix)
                    updated = True
                    break

    return sudoku_matrix, possible_matrix, updated


def gen_possible(sudoku_matrix):
    possible_matrix = [[[1,2,3,4,5,6,7,8,9] for _ in range(9)] for _ in range(9)]
    for i, row in enumerate(sudoku_matrix):
        for j, val in enumerate(row):
            if val == 0:
                continue

            possible_matrix[i][j] = []

            # Remove from column
            for r in range(9):
                if val in possible_matrix[r][j]:
                    possible_matrix[r][j].remove(val)

            # Remove from row
            for c in range(9):
                if val in possible_matrix[i][c]:
                    possible_matrix[i][c].remove(val)

            # Remove from 3x3 box
            box_row = i // 3
            box_col = j // 3
            for bi in range(box_row * 3, (box_row + 1) * 3):
                for bj in range(box_col * 3, (box_col + 1) * 3):
                    if val in possible_matrix[bi][bj]:
                        possible_matrix[bi][bj].remove(val)

    return possible_matrix

def solver(sudoku_matrix):
    
    possible_matrix = gen_possible(sudoku_matrix)
          
    while any(0 in row for row in sudoku_matrix):

        sudoku_matrix, possible_matrix, updated = logical_steps(sudoku_matrix, possible_matrix)
        while updated:
            sudoku_matrix, possible_matrix, updated = logical_steps(sudoku_matrix, possible_matrix)

        if any(0 in row for row in sudoku_matrix):
            first_i, first_j = next(
                (i, j)
                for i in range(9)
                for j in range(9)
                if sudoku_matrix[i][j] == 0
            )
            # Update that first zero to a random possiblity and see if it works
            for guess in possible_matrix[first_i][first_j]:
                # make a new grid
                new_grid = [row[:] for row in sudoku_matrix]
                new_grid[first_i][first_j] = guess

                solved = solver(new_grid)
                if solved is not None:
                    return solved
            
            return None
        
    return sudoku_matrix

sum = 0
for matrix in clean_matrices:
    solved = solver(matrix)
    num = 100*solved[0][0] + 10*solved[0][1] + solved[0][2]
    sum += num
        
print(f"Sum = {sum}")

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")