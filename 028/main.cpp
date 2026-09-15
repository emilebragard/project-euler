#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;


int main() {
    int grid_length = 1001;
    vector<int> diagonal_nums = {1};
    
    int diagonal_divisor = 2; int row_indicator = 1; int ri_increment = 2;
    
    for (int i = 3; diagonal_nums.size() < 2*grid_length - 1; i++){
        if ((i-1) % diagonal_divisor == 0){
            diagonal_nums.push_back(i);
        }
        if ((i-1) == row_indicator*8){
            row_indicator+= ri_increment; ri_increment++;
            diagonal_divisor += 2;
        }
    }

    int sum = 0;
    for (int num : diagonal_nums){
        sum+= num;
    }

    cout << sum;
}