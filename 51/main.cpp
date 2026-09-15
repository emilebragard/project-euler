#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

#include "functions.h"

using namespace std;


int main() {

    int size = 1000000;

    vector<bool> is_prime = generate_primes(size);
    
    vector<vector<int>> combos;
    find_combos(5, {0,1,2,3,4,5,6,7,8,9}, {}, combos, true);
    find_combos(6, {0,1,2,3,4,5,6,7,8,9}, {}, combos, true);
    vector<vector<int>> prime_combos;

    for (vector<int> num_vec : combos){
        if (is_prime[vec_to_int(num_vec)]){
            prime_combos.push_back(num_vec);
        }
    }

    int family_size = 7;

    for (vector<int> num_vec : prime_combos){
        
        int current_family_size = 0;
        int repeated_num = -1; int current_num = 0;
        while (repeated_num == -1 && current_num < 10){
            if (count(num_vec.begin(), num_vec.end(), current_num) > 1){
                repeated_num = current_num;
            }
            current_num++;
        }
        int prime_rotations = 1;
        for (int i = repeated_num + 1; i - prime_rotations < 3; i++){
            vector<int> new_num_vec;
            for (int j = 0; j < num_vec.size(); j++){
                if (num_vec[j] == repeated_num){
                    new_num_vec.push_back(i);
                }
                else{new_num_vec.push_back(num_vec[j]);}
            }
            if (is_prime[vec_to_int(new_num_vec)]){
                prime_rotations++;
            }
        }

        if (prime_rotations == 8){
            cout << vec_to_int(num_vec); break;
        }


    }

}