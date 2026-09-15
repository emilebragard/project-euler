#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

using namespace std;

void find_possible_sums(vector<int> current_list, int current_pos, vector<int> possible_nums, int target_sum, vector<vector<int>>& out_list){
    int current_sum = accumulate(current_list.begin(), current_list.end(), 0);
    vector<int> new_list = current_list;
    if (possible_nums[current_pos] == 1){
        for (int i = 0; i < target_sum - current_sum; i++){
            new_list.push_back(1);
        }
        out_list.push_back(new_list);
    }
    else{
        for (int num = 0; num <= (target_sum - current_sum) / possible_nums[current_pos] ; num++){
            if(num > 0){
                new_list.push_back(possible_nums[current_pos]);
            }
            find_possible_sums(new_list, current_pos + 1, possible_nums, target_sum, out_list);
        }
    }
}

int main() {

    vector<vector<int>> possible_sums;

    find_possible_sums({}, 0, {200,100,50,20,10,5,2,1},200, possible_sums);

    cout << possible_sums.size();

}