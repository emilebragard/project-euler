#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    vector<int> digits_a = {1};
    vector<int> digits_b = {1};
    vector<int> digits_c = {1};
    for (int i = 2; digits_a.size() < 1000; i++){

        int carry = 0;
        if (digits_b.size() > digits_a.size()){
            digits_a.push_back(0);
        }
        for (int j = 0; j < digits_b.size(); j++){
            int added = digits_a[j] + digits_b[j] + carry;
            carry = added / 10;
            digits_c[j] = added % 10;
        }

        if (carry > 0){ digits_c.push_back(carry);}

        digits_a = digits_b; digits_b = digits_c; 
        cout << i << " " << digits_a.size() << endl;
    }

}