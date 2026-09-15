#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

void find_combos(int size, vector<int> potential_digits, vector<int> currentnum, vector<vector<int>>& combos){
    for (int i = 0; i < potential_digits.size(); i++){
        vector<int> new_num = currentnum;
        new_num.push_back(potential_digits[i]);
        if (new_num.size() == size){
            if (new_num[0] != 0){
                combos.push_back(new_num);
            }
        }
        else{
            find_combos(size, potential_digits, new_num, combos);
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

    map<int,int> factorial;
    for (int i = 0; i < 10; i++){
        int current_factorial = 1;
        for (int n = 2; n <= i; n++){
            current_factorial *= n;
        }
        factorial[i] = current_factorial;
        // cout << i << " " << current_factorial << endl;
    }

    vector<int> digits = {1,2,3,4,5,6,7,8,9,0};
    vector<vector<int>> digit_combos;
    find_combos(3, digits, {}, digit_combos);
    find_combos(4, digits, {}, digit_combos);
    find_combos(5, digits, {}, digit_combos);
    find_combos(6, digits, {}, digit_combos);
    find_combos(7, digits, {}, digit_combos);

    int digit_factorial_sum = 0;

    for (vector<int> number_vec : digit_combos){
        int number = vec_to_int(number_vec); 
        int factorial_sum = 0;
        for (int digit : number_vec){
            factorial_sum += factorial[digit];
        }

        if (number == factorial_sum){
            cout << number << endl;
            digit_factorial_sum += number;
        }
    }

    cout << digit_factorial_sum;

}