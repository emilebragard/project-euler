#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    vector<long long int> abundant_nums;
    for (int i = 2; i < 28123; i++){
        int div_sum = 1;


        for (int j = sqrt(i); j > 1; j--){
            if (i % j == 0){
                div_sum += j; 
                if (i/j != j){div_sum += i/j;}

            }
        }

        if (div_sum > i){
            abundant_nums.push_back(i);
        }
    }

    vector<bool> sum_of_two_abundants;
    for (int i = 0; i <28123; i++){
        sum_of_two_abundants.push_back(false);
    }

    for (int i = 0; i < abundant_nums.size(); i++){
        for (int j = i; j < abundant_nums.size(); j++){
            if (abundant_nums[i]+abundant_nums[j] < 28123){
            sum_of_two_abundants[abundant_nums[i]+abundant_nums[j]]=true;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i < 28123; i++){
        if (!sum_of_two_abundants[i]){
            sum+= i;
        }
    }
    cout << sum;
    
}