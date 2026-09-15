
def generate_map_cubes(limit):
    cube_map = {}
    for i in range(1,limit):
        cube = i**3
        key = ''.join(sorted(str(cube)))
        if key in cube_map:
            cube_map[key].append(cube)
        else:
            cube_map[key] = [cube]
    return cube_map

def find_smallest_cube(cube_map):
    for key, cubes in cube_map.items():
        if len(cubes) == 5:
            print("Smallest cube with 5 permutations:", cubes[0])
            break

cube_map = generate_map_cubes(10000)
find_smallest_cube(cube_map)
    