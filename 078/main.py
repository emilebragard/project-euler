import time


start_time = time.time()

def gen__generalized_pentagonal(pentagonal_nums): 
    n = len(pentagonal_nums) + 2
    k = n // 2
    if n % 2 == 1:
        k = -k
    pentagonal_nums.append(int(k * (3*k - 1) / 2)) 

goal_div = 1_000_000

generalized_pentagonal_nums = []
for i in range(goal_div):
    gen__generalized_pentagonal(generalized_pentagonal_nums)

num_of_pents = 2

p = [1,1,2]

while p[-1] % goal_div != 0:
    n = len(p)
    if n == generalized_pentagonal_nums[num_of_pents]:
        num_of_pents += 1
    num = 0
    back_iters = generalized_pentagonal_nums[0:num_of_pents]
    for idx, pent_num in enumerate(back_iters):
        if idx % 4 < 2:
            num += p[-pent_num]
        else:
            num -= p[-pent_num]
    p.append(num)

print(len(p) - 1)

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")