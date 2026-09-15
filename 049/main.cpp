#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

#include "functions.h"

using namespace std;


int main() {

    vector<bool> is_prime = generate_primes(10000);
    vector<vector<int>> permutations;
    find_combos(4, {1,2,3,4,5,6,7,8,9,0}, {}, permutations, true);
    sort(permutations.begin(),permutations.end());

    vector<vector<int>> prime_permutations;

    for (vector<int> num_vec : permutations){
        if (is_prime[vec_to_int(num_vec)]){
            prime_permutations.push_back(num_vec);
        }
    }

    for (int i = 0; i < prime_permutations.size(); i++){
        vector<int> first_num_vec = prime_permutations[i];
        int first_num = vec_to_int(first_num_vec);
        
        for (int j = i + 1; (first_num + 2*(vec_to_int(prime_permutations[j]) - first_num)) < 10000 && j < prime_permutations.size(); j++){

            vector<int> second_num_vec = prime_permutations[j];
            int second_num = vec_to_int(second_num_vec);

            int difference = second_num - first_num;
            int third_num = second_num + difference;

            vector<int> third_num_vec = int_to_vec(third_num);

            if (is_prime[third_num]){

                vector<int> first_num_sorted = first_num_vec; sort(first_num_sorted.begin(), first_num_sorted.end());
                vector<int> second_num_sorted = second_num_vec; sort(second_num_sorted.begin(), second_num_sorted.end());
                vector<int> third_num_sorted = third_num_vec; sort(third_num_sorted.begin(), third_num_sorted.end());

                if (first_num_sorted == second_num_sorted && second_num_sorted == third_num_sorted){
                    cout << first_num << " " << second_num << " " << third_num << endl;
                    cout << first_num <<  second_num << third_num << endl;
                }

            }
    
        }

    }

}