#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

using namespace std;

vector<bool> generate_primes(int max){
    vector<int> primes;
    primes.push_back(2); primes.push_back(3);

    vector<bool> is_prime = {};
    for (int i = 0; i <= max; i++){
        is_prime.push_back(false);
    }
    is_prime[2] = true; is_prime[3] = true;

    for(int i = 5; primes.back() < max; i = i + 2){
        bool prime = true;
        for (int j = 0; j < primes.size()-1; j++){
            if (i% primes[j] == 0){
                prime = false;
                break;}
            }
        
        if (prime){
        primes.push_back(i);
        is_prime[i] = true;
        }
    }

    return is_prime;
}

void find_rotations(const vector<int> number_vec, vector<vector<int>>& rotations){
    rotations.push_back(number_vec);
    vector<int> rot_vec = number_vec;
    for (int i = 1; i < number_vec.size(); i ++){
        int first = rot_vec[0];
        rot_vec.erase(rot_vec.begin());
        rot_vec.push_back(first);
        rotations.push_back(rot_vec);
    }
}

void find_combos(int size, vector<int> potential_digits, vector<int> currentnum, vector<vector<int>>& combos, bool allow_repeats){
    for (int i = 0; i < potential_digits.size(); i++){
        vector<int> new_num = currentnum;
        new_num.push_back(potential_digits[i]);
        
        vector<int> new_digits = potential_digits;
        if (!allow_repeats){
        new_digits.erase(new_digits.begin() + i);}

        if (new_num.size() == size){
            if (new_num[0] != 0){
                combos.push_back(new_num);
            }
        }
        else{
            find_combos(size, new_digits, new_num, combos, allow_repeats);
        }
    }
}

void removeElement(std::vector<int>& vec, int element) {
    vec.erase(std::remove(vec.begin(), vec.end(), element), vec.end());
}

int vec_to_int(const vector<int>& vec){
    int num = 0;
    for (int a = vec.size()-1; a >= 0; a--){
        num += vec[a]* pow(10, vec.size()-a-1);
    }
    return num;
}


int main() {

    int size = 1000000;
    vector<bool> is_prime = generate_primes(size);
    cout << "Primes calculated" << endl;

    vector<int> digits = {0,1,2,3,4,5,6,7,8,9};
    vector<vector<int>> possible_nums;
    int size_digits = 0; int alter_size = size-1;
    while (alter_size > 0){
        size_digits++; alter_size = alter_size / 10;
    }
    for (int i = 1; i <= size_digits; i++){
        find_combos(i,digits,{},possible_nums,true);
    }

    vector<int> circular_primes;

    for (int i = 0; i < possible_nums.size(); i++){

        vector<int> potential_num_vec = possible_nums[i];
        int potential_num = vec_to_int(potential_num_vec);
        
        vector<vector<int>> rotations;
        find_rotations(potential_num_vec, rotations);
        bool all_prime = true;
        for (vector<int> rotation : rotations){
            if (!is_prime[vec_to_int(rotation)]){
                all_prime = false;
                break;
            }
        }

        if (all_prime){
            for (vector<int> rotation : rotations){
                int rotation_num = vec_to_int(rotation);
                if (find(circular_primes.begin(),circular_primes.end(), rotation_num) == circular_primes.end()){
                    circular_primes.push_back(rotation_num);
                }
                
            }
        }
    }


    for (int num : circular_primes){
        cout << num << " ";
    }

    cout << endl << circular_primes.size();

}