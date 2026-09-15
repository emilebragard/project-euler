#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

#include "functions.h"

using namespace std;


bool same_digits(vector<int> num_vec, int multiplier){
    vector<int> multiplied = vec_multiply(num_vec, {multiplier});
    if (multiplied.size() == num_vec.size()){
        vector<int> num_vec1 = num_vec; vector<int> multiplied1 = multiplied;
        sort(num_vec1.begin(), num_vec1.end());
        sort(multiplied1.begin(), multiplied1.end());
        if (num_vec1 == multiplied1){
            return true;
        }
        else{return false;}
    }
    else{return false;}
}


int main() {

    int number_size = 6;
    bool num_found = false;
    while (!num_found){
        vector<vector<int>> number_list;
        permutations(number_size, {0,1,2,3,4,5,6,7,8,9}, {}, number_list, true);

        for (vector<int> num_vec : number_list){
            if (num_vec[0] > 1 || num_vec[1] > 6){
                // Don't check
            }
            else{
                
                if (same_digits(num_vec, 6) && same_digits(num_vec, 5) && same_digits(num_vec, 4)){
                    if (same_digits(num_vec, 3) && same_digits(num_vec, 2)){
                        cout << vec_to_int(num_vec) << endl;
                        num_found = true;
                        break;
                    }
                }
            }
        }

        number_size++;
    }

}