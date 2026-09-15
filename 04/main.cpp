#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


bool is_palindrome(int number){
    vector<int> digits;
    int current_num = number;
    while (current_num >=1){
        digits.push_back(current_num %10);
        current_num = current_num / 10;
    }
    for (int i = 0; i < digits.size()/2 + 1; i++){
        if (digits[i] != digits[digits.size()-i-1]){
            return false;
        }
    }
    return true;
}

int main() {
    int max_palindrome = 0;
    for (int i = 999; i > 99; i--){
        for (int j = 999; j > 99; j--){
            if ((i*j > max_palindrome)&&(is_palindrome(i*j))){
                max_palindrome = i*j;
            }
        }
    }
    cout << max_palindrome;

}