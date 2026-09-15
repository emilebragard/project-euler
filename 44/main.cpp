#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;


void generate_pentagonal(vector<long long int>& pentagonal_nums, vector<bool>& is_pentagonal){
    long long int n = pentagonal_nums.size();
    pentagonal_nums.push_back((n* (3*n - 1) / 2));
    while (is_pentagonal.size() < pentagonal_nums.back() + 1)
    {
        is_pentagonal.push_back(false);
    }
    is_pentagonal[pentagonal_nums.back()] = true;
}


int main() {

    vector<long long int> pentagonal = {0,1};
    vector<bool> is_pentagonal = {0,1};
    generate_pentagonal(pentagonal, is_pentagonal);

    bool found = false;

    for (int i = 2; !found; i++){
        if (pentagonal.size() - 1 < i){
        generate_pentagonal(pentagonal, is_pentagonal);}
        for (int j = 1; j < i; j++){
            if (is_pentagonal[pentagonal[i] - pentagonal[j]]){

                while (pentagonal.back() < pentagonal[i] + pentagonal[j]){
                    generate_pentagonal(pentagonal, is_pentagonal);
                }

                if (is_pentagonal[pentagonal[i] + pentagonal[j]]){
                    cout << pentagonal[i] - pentagonal[j];
                    found = true;
                    break;
                }

            }
        }

    }

}