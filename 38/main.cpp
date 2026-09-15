#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> vec_multiply(vector<int>& a, vector<int>& b){
    vector<int> answer_vec;
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

    reverse(a.begin(),a.end()); reverse(b.begin(), b.end());
    return answer_vec;
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


int main() {

    vector<int> digits = {1,2,3,4,5,6,7,8,9};
    vector<int> digits_no9 = {1,2,3,4,5,6,7,8};
    vector<vector<int>> four_digit_combos;
    find_combos(4, digits_no9, {9}, four_digit_combos, false);

    int max_pandigit = 0;

    for (vector<int> vec : four_digit_combos){
        int num = vec_to_int(vec);
        long long int pot_pandig = num * 100000 + num*2;
        vector<int> pot_pandig_vec = int_to_vec(pot_pandig);
        sort(pot_pandig_vec.begin(), pot_pandig_vec.end());
        if (pot_pandig_vec == digits){
            cout << pot_pandig << " ";
            if (pot_pandig > max_pandigit){max_pandigit = pot_pandig;}
        }
    }

    cout << endl << max_pandigit;
}