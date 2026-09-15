#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

using namespace std;

void find_combos(int size, vector<int> potential_digits, vector<int> currentnum, vector<vector<int>>& combos){
    for (int i = 0; i < potential_digits.size(); i++){
        vector<int> new_num = currentnum;
        new_num.push_back(potential_digits[i]);
        vector<int> new_digits = potential_digits;
        new_digits.erase(new_digits.begin() + i);
        if (new_num.size() == size){
            combos.push_back(new_num);
        }
        else{
            find_combos(size, new_digits, new_num, combos);
        }
    }
}

void removeElement(std::vector<int>& vec, int element) {
    vec.erase(std::remove(vec.begin(), vec.end(), element), vec.end());
}

int vec_to_int(const vector<int> vec){
    int num = 0;
    for (int a = 0; a < vec.size(); a++){
        num += vec[a]* pow(10, a);
    }
    return num;
}


int main() {

    vector<int> digits = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> two_digit_combos;
    find_combos(2, digits, {}, two_digit_combos);

    vector<pair<int,int>> digit_cancellers = {};

    for (int i = 0; i < two_digit_combos.size(); i ++){
        for (int j = 0; j < two_digit_combos.size(); j++){

            // Define both numbers clearly
            vector<int> num_vec = two_digit_combos[i];
            vector<int> denom_vec = two_digit_combos[j];

            // Determine cancelling number (if there is one)
            int num_match = -1;
            if (num_vec[0] == denom_vec[1]){
                // cout << num_vec[0] << num_vec[1] << " " << denom_vec[0] << denom_vec[1];
                num_match = 0;
            }
            if (num_vec[1] == denom_vec[0]){
                num_match = 1;
            }

            
            // If there is a cancelling number, determine whether the fraction is < 1
            if (num_match >= 0){
                int num = vec_to_int(num_vec);
                int denom = vec_to_int(denom_vec);

                double simplified_denom = (denom + 0.0) / num;

                if (simplified_denom > 1){
                    // Remove the matching number
                    removeElement(denom_vec, num_vec[num_match]);
                    removeElement(num_vec, num_vec[num_match]); 

                    int num = vec_to_int(num_vec);
                    int denom = vec_to_int(denom_vec);

                    if (simplified_denom == (denom + 0.0) / num){
                        cout << num << " " << denom <<  endl;
                        digit_cancellers.push_back({num,denom});
                    }
                }
                // cout << endl;
            }

            
        }
    }

    // Find simplified fraction
    int currentNum = 1; int currentDenom = 1;

    for (const auto& pair : digit_cancellers){
        currentNum *= pair.first;
        currentDenom *= pair.second;
    }

    for (int num = 1; num <= currentDenom && num <= currentNum; num++){
        if (currentDenom % num == 0 && currentNum % num == 0){
            currentNum = currentNum / num;
            currentDenom = currentDenom / num;
        }
    }

    cout << currentNum << "/" << currentDenom;

}