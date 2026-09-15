#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    vector<int> nums;
    nums.push_back(2); int smallest_num = 2;
    for (int i = 3; i <=20; i++){
        int current = i;
        for (int j = 0; j < nums.size(); j++){
            if (current % nums[j] == 0){
                current = current / nums[j];
            }
        }
        nums.push_back(current);
        smallest_num *= current;
    }
    
    cout << smallest_num;
}