#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    vector<int> digits = {1};
    for (int i = 1; i <= 100; i++){

        int carry = 0;

        for (int j = 0; j < digits.size(); j++){
            int multiplied = i*digits[j] + carry;
            carry = multiplied / 10;
            digits[j] = multiplied % 10;
        }

        while (carry > 0){ 
            digits.push_back(carry%10);
            carry = carry / 10;
            }
    }

    int sum = 0;
    for (int digit : digits){
        sum += digit;
    }

    cout << sum;

}