import time, decimal
from math import sqrt

start_time = time.time()

decimal.getcontext().prec = 102

totalDigSum = 0

for natNum in range(1,100):
    if natNum not in [1,4,9,16,25,36,49,64,81,100]:
        num1 = decimal.Decimal(natNum)
        sqrt1 = num1.sqrt()
        list1 = str(sqrt1)
        totalDigSum+=int(list1[0])
        list1 = list1[list1.index('.')+1:list1.index('.')+100]
        print(list1, len(list1))
        
        for num in list1:
            totalDigSum+=int(num)

print(totalDigSum)

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")