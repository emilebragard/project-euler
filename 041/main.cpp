#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

using namespace std;

vector<bool> generate_primes(unsigned long long int max){

    vector<bool> is_prime(max + 1, true);
    is_prime[0] = false; is_prime[1] = false;

    for (unsigned long long int i = 2; i <= max; i++){
        if (is_prime[i]){
            for (unsigned long long int j = i; i*j <= max; j++){
                is_prime[i*j] = false;
            }
        }
    }

    return is_prime;
}

unsigned long long int vec_to_int(const vector<int>& vec){
    unsigned long long int num = 0;
    for (int a = vec.size()-1; a >= 0; a--){
        num += vec[a]* pow(10, vec.size()-a-1);
    }
    return num;
}

void find_combos(int size, vector<int> potential_digits, vector<int> currentnum, vector<vector<int>>& combos, bool allow_repeats){
    for (int i = 0; i < potential_digits.size(); i++){
        vector<int> new_num = currentnum;
        new_num.push_back(potential_digits[i]);
        
        vector<int> new_digits = potential_digits;
        if (!allow_repeats){
        new_digits.erase(new_digits.begin() + i);}

        if (new_num.size() == size){
            int digit_sum = 0;
            for (int num : new_num){
                digit_sum += num;
            }
            if (new_num.back() != 5 && new_num.back() % 2 != 0 && digit_sum % 3 != 0){
                combos.push_back(new_num);
            }
        }
        else{
            find_combos(size, new_digits, new_num, combos, allow_repeats);
        }
    }
}


int main() {

    vector<bool> is_prime = generate_primes(8000000);
    cout << "Primes generated. " << endl;
    vector<int> digits = {1,2,3,4,5,6,7};
    vector<vector<int>> numbers;
    find_combos(7, digits, {}, numbers, false);
    long long int max_pandigital_prime = 0;

    for (vector<int> num_vec : numbers){
        long long int num = vec_to_int(num_vec);
        if (is_prime[num]){
            if (num > max_pandigital_prime){
                max_pandigital_prime = num;
            }
        }
    }

    cout << max_pandigital_prime; 

   

}