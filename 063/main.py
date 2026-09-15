
def find_matches(num):
    maxed = False
    numlist = []
    current = 1
    while not maxed:
        powered_num = num ** current
        if len(str(powered_num)) == current:
            numlist.append(powered_num)
        elif len(str(powered_num)) < current:
            return numlist
        current+=1

master_list = [1]

for i in range(2,10):
    master_list = master_list + find_matches(i)

master_list = sorted(set(master_list))

print(master_list)
print(len(master_list))

