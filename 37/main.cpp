#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

using namespace std;

vector<bool> generate_primes(int max){

    vector<bool> is_prime(max + 1, true);
    is_prime[0] = false; is_prime[1] = false;

    for (int i = 2; i <= max; i++){
        if (is_prime[i]){
            for (int j = 2; i*j <= max; j++){
                is_prime[i*j] = false;
            }
        }
    }

    return is_prime;
}

void find_truncated_nums(const vector<int> number_vec, vector<vector<int>>& truncations){
    vector<int> trunc_vec = number_vec;
    // Right
    for (int i = 1; i < number_vec.size(); i ++){
        trunc_vec.erase(trunc_vec.begin());
        truncations.push_back(trunc_vec);
    }
    // Left
    trunc_vec = number_vec;
        for (int i = 1; i < number_vec.size(); i ++){
        trunc_vec.erase(trunc_vec.end()-1);
        truncations.push_back(trunc_vec);
    }
}

int vec_to_int(const vector<int>& vec){
    int num = 0;
    for (int a = vec.size()-1; a >= 0; a--){
        num += vec[a]* pow(10, vec.size()-a-1);
    }
    return num;
}

vector<int> int_to_vec(const int num){
    vector<int> num_vec;
    int altered_num = num;
    while (altered_num > 0){
        num_vec.push_back(altered_num % 10);
        altered_num = altered_num / 10;
    }
    reverse(num_vec.begin(),num_vec.end());
    return num_vec;
}


int main() {

    vector<bool> is_prime = generate_primes(1000000);

    int truncatable_prime_sum = 0;

    for (int i = 1; i < is_prime.size(); i++){
        if (is_prime[i]){

            vector<int> prime_vec = int_to_vec(i);

            if (prime_vec.size() != 1){

                vector<vector<int>> truncs;
                find_truncated_nums(prime_vec, truncs);

                bool all_prime = true;
                for (vector<int> num_vec : truncs){
                    if (!is_prime[vec_to_int(num_vec)]){
                        all_prime = false;
                        // break;
                    }
                }

                if (all_prime){
                    cout << i << " ";
                    truncatable_prime_sum += i;
                }
            }
        }
    }

    cout << endl << truncatable_prime_sum;


}