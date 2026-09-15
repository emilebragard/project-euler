#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

#include "functions.h"

using namespace std;


int main() {



    vector<int> final_number = {0};
    for (int num = 1; num <= 1000; num++){
        
        vector<int> num_vec = int_to_vec(num);
        vector<int> final_num_vec = num_vec;
        cout << num << endl;

        for (int power_num = 2; power_num <= num; power_num++){
            final_num_vec = vec_multiply(final_num_vec, num_vec);
        }
        final_number = vec_sum(final_number, final_num_vec);

    }

    for (int i = final_number.size() - 10; i < final_number.size(); i ++){
        cout << final_number[i];
    }

}