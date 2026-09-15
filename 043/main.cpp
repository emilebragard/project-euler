#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

long long int vec_to_int(const vector<int>& vec){
    long long int num = 0;
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

int main() {

    vector<int> digits = {0,1,2,3,4,5,6,7,8,9};
    vector<vector<int>> with_property;
    find_combos(10,digits,{},with_property,false);

    long long int sum = 0;
    for (vector<int> num_vec : with_property){
        cout << vec_to_int(num_vec) << " ";
        sum += vec_to_int(num_vec);
    }

    cout << endl << sum;

}