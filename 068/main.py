import itertools
import copy

def format_ring(sol_set):
    x = sol_set[0][-1]

    if x not in sol_set[1]:
        to_swap = -1
        for idx, subset in enumerate(sol_set[2:]):
            if x in subset:
                to_swap = idx + 2
        sol_set[1], sol_set[to_swap] = sol_set[to_swap], sol_set[1]
    
    if sol_set[1][1] != x:
        sol_set[1][1], sol_set[1][2] = sol_set[1][2], sol_set[1][1]
    
    if len(sol_set) > 2:
        sol_set = [sol_set[0]] + list(format_ring(sol_set[1:]))
        
    return sol_set

def to_str(sol_set):
    flattened = [item for sub in sol_set for item in sub]
    result_str = ''.join(map(str,flattened))
    return (result_str)

def gonringgen(size, desired_len):
    gonrings = []
    ref = list(itertools.combinations(range(1,2*size+1),size))
    
    for desired_num in range(6, 2*size*3 - 3):
        for combo in ref:
            nonref = [x for x in list(range(2*size, 0, -1)) if x not in combo]
            inner_combos = list(itertools.combinations(combo, 2))
            inner_combos.sort(key=sum)
            inner_idx = 0

            pos_assemblies = [[] for _ in range(size)]
            valid = True
            for pos, outer in enumerate(nonref):
                while (inner_idx < len(inner_combos)) and (outer + sum(inner_combos[inner_idx]) <= desired_num):
                    if outer + sum(inner_combos[inner_idx]) == desired_num:
                        pos_assemblies[pos].append(inner_combos[inner_idx])
                    inner_idx+=1
                if len(pos_assemblies[pos]) == 0:
                    valid = False
                    break
            

            if not valid: continue

            all_assemblies = itertools.product(*pos_assemblies)
            for assembly in all_assemblies:
                correct = True
                total_list = [item for sub in assembly for item in sub]
                for num in combo:
                    if total_list.count(num) !=2:
                        correct = False
                        break
                if not correct: continue
                
                final_format = [[nonref[idx]] + list(sub) for idx, sub in enumerate(assembly)]
                final_format.sort(key = lambda x: x[0])
                final_format = format_ring(final_format)
                final_str = to_str(final_format) 
                if (len(final_str) == desired_len):
                    gonrings.append(int(final_str))

                alternate_format = copy.deepcopy(final_format)
                alternate_format[0][1], alternate_format[0][2] = alternate_format[0][2], alternate_format[0][1]
                alternate_format = to_str(format_ring(alternate_format))
                if (len(alternate_format) == desired_len):
                    gonrings.append(int(alternate_format))
                
    gonrings.sort()
    return gonrings
         
print(max(gonringgen(5, 16)))