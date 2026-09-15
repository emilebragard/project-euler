from functions import gen_primes, gen_heptagonal, gen_hexagonal, gen_octagonal, gen_pentagonal, gen_primes, gen_square, gen_triangular
import copy

primes, is_prime = gen_primes(10 ** 6)
print("Primes calculated.")

found = False
cur = 0
concd_prime = []

poly_nums = [[] for _ in range(6)]

gen_triangular(poly_nums[0])
while poly_nums[0][-1] < 10000:
    gen_triangular(poly_nums[0])

gen_square(poly_nums[1])
while poly_nums[1][-1] < 10000:
    gen_square(poly_nums[1])

gen_pentagonal(poly_nums[2])
while poly_nums[2][-1] < 10000:
    gen_pentagonal(poly_nums[2])

gen_hexagonal(poly_nums[3])
while poly_nums[3][-1] < 10000:
    gen_hexagonal(poly_nums[3])

gen_heptagonal(poly_nums[4])
while poly_nums[4][-1] < 10000:
    gen_heptagonal(poly_nums[4])

gen_octagonal(poly_nums[5])
while poly_nums[5][-1] < 10000:
    gen_octagonal(poly_nums[5])

for polylist in poly_nums:
    while polylist[0] < 1000:
        polylist.pop(0)

import copy

def find_cyc_match(cur_num, polylists, found_nums):
    des_digs = cur_num % 100  # Desired digits to match in the next number's prefix
    for idx, polylist in enumerate(polylists):
        new_polylist = copy.deepcopy(polylists)  # Create a new list of lists without altering the original
        new_polylist.pop(idx)  # Remove the current polygonal list being iterated

        for num in polylist:
            if num // 100 == des_digs:  # Check if the prefix of the current number matches the suffix of the last number
                new_found_nums = copy.deepcopy(found_nums)  # Create a copy of the found numbers so far
                new_found_nums.append(num)  # Add the current number to the new list of found numbers

                if len(new_polylist) == 0:  # If there are no more lists to check, possibly found a complete cycle
                    # Check if the cycle is complete by ensuring the last number's suffix matches the first number's prefix
                    if len(new_found_nums) > 1 and new_found_nums[-1] % 100 == new_found_nums[0] // 100:
                        print("Cycle found:", new_found_nums)
                        print("Sum: ", sum(new_found_nums))
                        return True  # Optional: Return True to indicate a cycle was found
                else:
                    # Recursive call to continue searching with the updated lists
                    if find_cyc_match(num, new_polylist, new_found_nums):
                        return True  # Propagate the True return value up the call stack

    return False  # Optional: Indicate that no cycle was found along this path

found = False
new_polynums = copy.deepcopy(poly_nums)
polylist = copy.deepcopy(poly_nums[0])
new_polynums.pop(0)
for num in polylist:
    if find_cyc_match(num, new_polynums, [num]):
        break