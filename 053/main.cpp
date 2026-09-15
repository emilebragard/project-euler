#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

#include "functions.h"

using namespace std;

int main() {

    int value_count = 0;

    for (int n = 23; n <= 100; n++){
        for (int k = 1; k < n; k++){
            vector<int> num = nCk(n,k);
            if (greater_or_equal_to(num, {1,0,0,0,0,0,1})){
                value_count++;
            }
        }
    }

    cout << value_count;

}