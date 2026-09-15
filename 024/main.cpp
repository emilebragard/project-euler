#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

unsigned long long int factorial(unsigned int n){
    unsigned long long int result = 1;
    for (int i = 2; i <= n; i++){
        result *= i;
    }
    return result;
}

vector<long long int> perm_list(vector<long long int> nums){
    vector<long long int> perms = {};
    for (int i = 0; i < nums.size(); i++){
        int number = nums[i]* pow(10, nums.size()-1);
        if (nums.size() > 1){
            vector<long long int> remaining = nums;
            remaining.erase(remove(remaining.begin(), remaining.end(), nums[i]), remaining.end());
            vector<long long int> endings = perm_list(remaining);
            for (int j = 0; j < endings.size(); j++){
                perms.push_back(number + endings[j]);
            }
        }
        else{perms.push_back(number);}
    }

    return perms;
}

int main() {
    int permsize = 10;
    vector<long long int> perm_nums = {};
    for (int i = 0; i < permsize; i ++){
        perm_nums.push_back(i);
    }
    vector<long long int> lex_perm_list = perm_list(perm_nums);
    
    cout << lex_perm_list[999999];
    
}