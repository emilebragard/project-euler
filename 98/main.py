import time

start_time = time.time()

with open("0098_words.txt", "r") as f:
    content = f.read()
    words = [word.strip('"') for word in content.split(',')]

word_letters = [list(word) for word in words]

anagram_groups = {}
for word in words:
    key = tuple(sorted(word))
    if key not in anagram_groups:
        anagram_groups[key] = set()
    anagram_groups[key].add(word)

# Remove groups with only one word
anagram_groups = {k: v for k, v in anagram_groups.items() if len(v) > 1}

square_nums = [0]
base = 1
while square_nums[-1] < 10 ** 10:
    square_nums.append(base ** 2)
    base += 1

unique_digited_square_nums = [[] for _ in range(11)]
for num in square_nums:
    # check for duplicate digits
    if len(str(num)) == len(set(str(num))):
        unique_digited_square_nums[len(str(num))].append(num)

largest_special_square_num = 0

for group in anagram_groups:
    group_set = anagram_groups[group]
    group_items = list(group_set)
    base_order = range(len(group_items[0]))
    scrambled_order = [group_items[0].index(letter) for letter in group_items[1]]
    
    for squared_num in unique_digited_square_nums[len(group_items[0])]:
        digit_list = [int(d) for d in str(squared_num)]
        scrambled_digit_list = [digit_list[n] for n in scrambled_order]
        new_num = int(''.join(str(item) for item in scrambled_digit_list))
        if new_num in unique_digited_square_nums[len(group_items[0])]:
            largest = max(squared_num, new_num)
            if largest > largest_special_square_num:
                largest_special_square_num = largest

print(largest_special_square_num)

end_time = time.time()

print("elapsed time: ", end_time - start_time, " seconds")