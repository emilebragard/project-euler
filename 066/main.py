from math import sqrt
from functions import cont_frac_sqrt, cont_frac_calc



def D_solver(D):
    initial, period = cont_frac_sqrt(D)
    if period == []:
        return 0
    nums = [initial]
    current = 0
    while True:
        nums.append(period[current%len(period)])
        current+=1
        frac = cont_frac_calc(nums)
        if frac[0]**2 - D*frac[1]**2 == 1:
            return frac[0]
            
        

max = (-1,0)

for a in range(2,1000):
    if D_solver(a) > max[1]:
        max = (a, D_solver(a))

print(max)

