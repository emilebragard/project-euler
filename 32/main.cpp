#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> vec_multiply (vector<int>& a, vector<int>& b){
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


int main() {

    vector<int> digits = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> one_digit_combos;
    find_combos(1, digits, {}, one_digit_combos);

    vector<int> pandigital_sums;

    

    for (int i = 0; i < one_digit_combos.size(); i ++){
        vector<int> new_digs = digits;
        for (int num : one_digit_combos[i]){
            removeElement(new_digs, num);
        }
        vector<vector<int>> four_digit_combos;  
        find_combos(4, new_digs, {}, four_digit_combos);
        for (vector<int> num : four_digit_combos){
            vector<int> product = vec_multiply(one_digit_combos[i], num);
            if (product.size() == 4){
                vector<int> needed_digs = new_digs;
                for (int digit : num){
                    removeElement(needed_digs, digit);
                }
                sort(product.begin(),product.end());
                if (product == needed_digs){
                    product = vec_multiply(one_digit_combos[i], num);
                    int found_product = 0;
                    for (int a = 0; a < product.size(); a++){
                        found_product += product[a]* pow(10, a);
                    }
                    cout << found_product << endl;
                    if (find(pandigital_sums.begin(), pandigital_sums.end(), found_product) == pandigital_sums.end()){
                    pandigital_sums.push_back(found_product);}
                }
            }
        }
    }


    vector<vector<int>> two_digit_combos;
    find_combos(2, digits, {}, two_digit_combos);

    for (int i = 0; i < two_digit_combos.size(); i ++){
        vector<int> new_digs = digits;
        for (int num : two_digit_combos[i]){
            removeElement(new_digs, num);
        }
        vector<vector<int>> three_digit_combos;  
        find_combos(3, new_digs, {}, three_digit_combos);
        for (vector<int> num : three_digit_combos){
            vector<int> product = vec_multiply(two_digit_combos[i], num);
            if (product.size() == 4){
                vector<int> needed_digs = new_digs;
                for (int digit : num){
                    removeElement(needed_digs, digit);
                }
                sort(product.begin(),product.end());
                if (product == needed_digs){
                    product = vec_multiply(two_digit_combos[i], num);
                    int found_product = 0;
                    for (int a = 0; a < product.size(); a++){
                        found_product += product[a]* pow(10, a);
                    }
                    cout << found_product << endl;
                    if (find(pandigital_sums.begin(), pandigital_sums.end(), found_product) == pandigital_sums.end()){
                    pandigital_sums.push_back(found_product);}
                }
            }
        }
    }

    cout << accumulate(pandigital_sums.begin(), pandigital_sums.end(), 0);

}