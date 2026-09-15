#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

using namespace std;

int vec_to_int(const vector<int> vec){
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

bool is_palindromic(vector<int> num){
    bool palindrome = true;
    for (int i = 0; i <= num.size()-1; i++){
        if (num[i] != num[num.size() - 1 - i]){
            palindrome = false;
            break;
        }
    }
    return palindrome;
}

vector<int> binary(vector<int> base10_num_vec){
    vector<int> binary_vec;
    int base10_num = vec_to_int(base10_num_vec);
    while (base10_num > 0){
        binary_vec.push_back(base10_num % 2);
        base10_num /= 2;
    }
    reverse(binary_vec.begin(),binary_vec.end());
    return binary_vec;
}

int main() {

    int double_base_sum = 0;

    for (int i = 1; i < 1000000; i++){
        vector<int> num = int_to_vec(i);
        if (is_palindromic(num)){
            if (is_palindromic(binary(num))){
                double_base_sum += i;
                cout << i << " - " << vec_to_int(binary(num)) << endl;
            }
        }
    }

    cout << double_base_sum;

}