#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <numeric>

#include "functions.h"

using namespace std;

int main() {
    
    int max_dig_sum = 0;

    for (int i = 1; i < 100; i ++){
        for (int j = 1; j < 100; j++){
            int dig_sum = digit_sum(power(int_to_vec(i), j));
            if (dig_sum > max_dig_sum) max_dig_sum = dig_sum;
        }
    }

    cout << max_dig_sum;

    return 0;
}
