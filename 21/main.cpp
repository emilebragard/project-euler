#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    vector<long long int> proper_divisor_sum;
    proper_divisor_sum.push_back(0), proper_divisor_sum.push_back(0);

    vector<long long int> amicable_nums;
    for (int i = 2; i < 10000; i++){
        int div_sum = 1;


        if (i % int(sqrt(i)) == 0){
            div_sum += int(sqrt(i));
        }
        for (int j = sqrt(i); j > 1; j--){
            if (i % j == 0){
                div_sum += j; div_sum += i/j;
            }
        }
        proper_divisor_sum.push_back(div_sum);
        if (div_sum < proper_divisor_sum.size() - 1){
            if (proper_divisor_sum[div_sum] == i){
                amicable_nums.push_back(i); amicable_nums.push_back(div_sum);
                cout << i << " " << div_sum << endl;
            }
        }
    }

    int sum = 0;
    for (int amicable : amicable_nums){
        sum+= amicable;
    }
    cout << sum;
    
}