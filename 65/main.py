from functions import cont_frac_calc


e_list = [2]
for i in range(1, 34):
    e_list.extend([1, 2*i, 1])

e = cont_frac_calc(e_list[:100])
num_dig_sum = [int(x) for x in str(e[0])]

print(sum(num_dig_sum))