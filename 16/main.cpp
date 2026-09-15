#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    vector<int> digits = {2};
    for (int i = 1; i < 1000; i++){

        int carry = 0;

        for (int j = 0; j < digits.size(); j++){
            int doubled = 2*digits[j] + carry;
            carry = doubled / 10;
            digits[j] = doubled % 10;
        }

        if (carry > 0){ digits.push_back(carry);}
    }

    int sum = 0;
    for (int digit : digits){
        sum += digit;
    }

    cout << sum;

}