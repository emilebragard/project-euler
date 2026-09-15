from functions import cont_frac_sqrt


odd_period = 0
for i in range(2, 10001):
    print(i, cont_frac_sqrt(i))
    if len(cont_frac_sqrt(i)) % 2 == 1:
        odd_period += 1
    
print(odd_period)


