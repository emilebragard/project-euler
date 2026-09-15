#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

vector<int> int_to_vec(const int num){
    if (num == 0){return {0};}
    vector<int> num_vec;
    int altered_num = num;
    while (altered_num > 0){
        num_vec.push_back(altered_num % 10);
        altered_num = altered_num / 10;
    }
    reverse(num_vec.begin(),num_vec.end());
    return num_vec;
}

int vec_to_int(const vector<int>& vec){
    int num = 0;
    for (int a = vec.size()-1; a >= 0; a--){
        num += vec[a]* pow(10, vec.size()-a-1);
    }
    return num;
}

void removeElement(std::vector<int>& vec, int element) {
    vec.erase(std::remove(vec.begin(), vec.end(), element), vec.end());
}

vector<bool> generate_primes(long long int max){

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

void find_combos(int size, vector<int> potential_digits, vector<int> currentnum, vector<vector<int>>& combos, bool allow_repeats){

    for (int i = 0; i < potential_digits.size(); i++){
        vector<int> new_num = currentnum;
        new_num.push_back(potential_digits[i]);
        
        vector<int> new_digits = potential_digits;
        if (!allow_repeats){
        new_digits.erase(new_digits.begin() + i);}

        if (new_num.size() == size ){
            if (new_num[0] != 0){
                vector<int> primes = {1,2,3,5,7,11,13,17};
                bool valid = true;
                for (int i = 0; i < 8; i++){
                    if (vec_to_int({new_num[i], new_num[i+1], new_num[i+2]}) % primes[i] != 0){
                        valid = false; break;
                    }
                }
                if (valid){
                    combos.push_back(new_num);
                }
            }
        }
        else{
            find_combos(size, new_digits, new_num, combos, allow_repeats);
        }
    }
}

int find_max(vector<int> vec){
    int max_num = 0;
    int max_pos = -1;
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] > max_num){
            max_num = vec[i];
            max_pos = i;
        }
    }
    return max_pos;
}

vector<int> vec_multiply(const vector<int> vec1, const vector<int> vec2){
    vector<int> answer_vec;
    vector<int> a = vec1; vector<int> b = vec2;
    reverse(a.begin(),a.end()); reverse(b.begin(), b.end());
    for (int i = 0; i < a.size() + b.size(); i++){
        answer_vec.push_back(0);
    }
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < b.size(); j++){
            int current_digit = answer_vec[i+j] + a[i]*b[j];
            answer_vec[i+j] = current_digit % 10;
            answer_vec[i+j+1] += current_digit / 10;
        }
    }

    while (answer_vec.back() == 0){
        answer_vec.pop_back();
    }

    reverse(answer_vec.begin(),answer_vec.end());
    return answer_vec;
}

vector<int> vec_sum (const vector<int> vec1, const vector<int> vec2){
    vector<int> a = vec1; vector<int> b = vec2;
    reverse(a.begin(),a.end()); reverse(b.begin(), b.end());    
    vector<int> sum;
    int carry = 0;
    while (a.size() < b.size()){a.push_back(0);}
    while (b.size() < a.size()){b.push_back(0);}

    for (int i = 0; i < a.size(); i ++){
        sum.push_back((a[i] + b[i] + carry) % 10);
        carry = (a[i] + b[i] + carry) / 10;
    }

    reverse(sum.begin(),sum.end());

    return sum;
}

void find_prime_factors(vector<vector<int>>& prime_factors, vector<bool>& has_prime_factors, const vector<bool> is_prime){

    vector<int> factor_combo;
    int num = prime_factors.size();

    for (int i = 2; i < sqrt(num); i++){
        if (num % i == 0){
            int j = num/i;
            bool i_works = false; bool j_works = false;
            if (is_prime[i]){
                factor_combo.push_back(i); i_works = true;
            }
            if (has_prime_factors[i]){
                for (int num : prime_factors[i]){
                    if (find(factor_combo.begin(), factor_combo.end(), num) == factor_combo.end()){
                        factor_combo.push_back(num);}
                }
                i_works = true;
            }
            if (is_prime[j]){
                if (find(factor_combo.begin(), factor_combo.end(), j) == factor_combo.end()){
                factor_combo.push_back(j);
                j_works = true;}
            }
            if (has_prime_factors[j]){
                for (int num : prime_factors[j]){
                    if (find(factor_combo.begin(), factor_combo.end(), num) == factor_combo.end()){
                        factor_combo.push_back(num);}
                }
                j_works = true;
            }

            if (i_works && j_works){
                prime_factors.push_back(factor_combo);
                has_prime_factors.push_back(true);
                return;
            }

        }

    }

    prime_factors.push_back({});
    has_prime_factors.push_back(false);
}
