#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;


int main() {

    long long int combo10 = 8;
    long long int combo20 = pow(combo10,2) + 1;
    long long int combo50 = pow(combo10, 5) + combo10 * pow(combo20, 2) + combo20 * pow(combo10, 3) + 1;

    long long int combo100 = pow(combo50, 2) + pow(combo20, 5) + 1;
    cout << combo100 << endl;    
    vector<int> combo100_vec = {};
    while (combo100 > 0){
        combo100_vec.push_back(combo100 % 10);
        combo100 = combo100 / 10;
    }

    vector<int> combo200_vec = {};
    for (int i = 0; i < 30; i++){
        combo200_vec.push_back(0);
    }

    for (int a = 0; a < combo100_vec.size(); a++){
        for (int b = 0; b < combo100_vec.size(); b++){
            int current_digit = combo200_vec[a+b] + combo100_vec[a]*combo100_vec[b];
            combo200_vec[a+b] = current_digit % 10;
            combo200_vec[a+b+1] += current_digit / 10;
        }
    }  

    while (combo200_vec.back() == 0){
        combo200_vec.pop_back();
    }

    combo200_vec[0] += 1;
    combo200_vec[1] += combo200_vec[0] / 10;
    combo200_vec[0] = combo200_vec[0] % 10;

    for (int i = combo200_vec.size() - 1; i >=0; i --){
        cout << combo200_vec[i];
    }




}