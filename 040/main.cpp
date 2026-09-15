#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

vector<int> int_to_vec(const int num){
    if (num == 0){return {0};}
    vector<int> num_vec;
    int altered_num = num;
    while (altered_num > 0){
        num_vec.push_back(altered_num % 10);
        altered_num = altered_num / 10;
    }
    reverse(num_vec.begin(),num_vec.end());
    return num_vec;
}

int vec_to_int(const vector<int>& vec){
    int num = 0;
    for (int a = vec.size()-1; a >= 0; a--){
        num += vec[a]* pow(10, vec.size()-a-1);
    }
    return num;
}

void removeElement(std::vector<int>& vec, int element) {
    vec.erase(std::remove(vec.begin(), vec.end(), element), vec.end());
}


int main() {

    vector<int> giant_decimal;

    for (int i = 0; giant_decimal.size() < 1000000 + 20; i++){
        vector<int> num_vec = int_to_vec(i);
        for (int num : num_vec){
            giant_decimal.push_back(num);
        }
    }


    cout << giant_decimal[1] << " " << giant_decimal[10] << " " << giant_decimal[100] << " " << giant_decimal[1000] << " " << giant_decimal[10000] << " " << giant_decimal[100000] << " " << giant_decimal[1000000];
    cout << endl << giant_decimal[1] * giant_decimal[10] * giant_decimal[100] * giant_decimal[1000] * giant_decimal[10000] * giant_decimal[100000] * giant_decimal[1000000];

}