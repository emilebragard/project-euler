#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <numeric>

#include "functions.h"

using namespace std;

vector<vector<int>> root_two_sequence(int num){
    vector<vector<int>> seq;
    seq.push_back({0}); seq.push_back({1});
    for (int i = 2; i <= num; i++){
        seq.push_back(vec_add(vec_multiply(seq[i-1], {2}), seq[i-2]));
    }
    return seq;
}


int main() {
    int n = 1000;
    vector<vector<int>> seq = root_two_sequence(n+1);

    int case_count = 0;

    for (int i = 1; i <= n; i++){
        vector<int> denom = seq[i+1];
        vector<int> num = vec_add(seq[i], denom);
        if (num.size() > denom.size()) case_count++;
    }

    cout << case_count;

    return 0;
}
