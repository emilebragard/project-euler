#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

bool compareSegments(const vector<long long int>& vec, long long int comparison_size, long long int start) {

    for (long long int i = 0; i < comparison_size; i++) {
        if (vec[i+start] != vec[i + comparison_size + start]) {
            return false;
        }
        if (vec[i+start + comparison_size] != vec[i + comparison_size*2 + start]) {
            return false;
        }
        if (vec[i+start + 2*comparison_size] != vec[i + comparison_size*3 + start]) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<long long int> recurring_digits = {0,0};
    for (long long int num = 2; num < 1000; num++){
        cout << num << " ";
        recurring_digits.push_back(0);
        vector<long long int> digit_vector = {};
        long long int current_dividend = 10;
        while (current_dividend != 0){
            digit_vector.push_back(current_dividend / num);
            current_dividend = (current_dividend % num) * 10;
            for (long long int start = 0; start < digit_vector.size() / 5; start++){
                for (long long int i = 1; i < digit_vector.size() / 4; i++){
                    if (compareSegments(digit_vector, i, start)){
                        recurring_digits[num] = i;
                        current_dividend = 0;
                        break;
                    }
                }
            }
        }
        
    }
    long long int max = 0;
    long long int max_index = 0;
    for (long long int i = 0; i < recurring_digits.size(); i++){
        if (recurring_digits[i] > max){
            max = recurring_digits[i];
            max_index = i;
        }
    }
    cout << endl << endl << max_index;


    }