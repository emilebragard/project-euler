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

void generate_hexagonal(vector<long long int>& hexagonal_nums){
    long long int n = hexagonal_nums.size();
    hexagonal_nums.push_back((n* (2*n-1)));
}

void generate_pentagonal(vector<long long int>& pentagonal_nums){
    long long int n = pentagonal_nums.size();
    pentagonal_nums.push_back((n* (3*n - 1) / 2));
}


void generate_triangular(vector<long long int>& triangular_nums){
    long long int n = triangular_nums.size();
    triangular_nums.push_back((n* (n+1) / 2));
}

int main() {

    vector<long long int> pentagonal = {0,1};

    vector<long long int> triangular = {0,1};

    vector<long long int> hexagonal = {0,1};
    
    generate_hexagonal(hexagonal);
    generate_pentagonal(pentagonal);

    while (hexagonal.back() != triangular.back() || triangular.back() != pentagonal.back() /*|| hexagonal.back() == 40755*/){
        generate_hexagonal(hexagonal);
        cout << hexagonal.back() << " ";

        while (hexagonal.back() > triangular.back()){
            generate_triangular(triangular);
        }

        cout << triangular.back() << " ";

        while (hexagonal.back() > pentagonal.back()){
            generate_pentagonal(pentagonal);
        }

        cout << pentagonal.back() << endl;
    }
    
    generate_pentagonal(pentagonal);

    while (hexagonal.back() != triangular.back() || triangular.back() != pentagonal.back() /*|| hexagonal.back() == 40755*/){
        generate_hexagonal(hexagonal);
        cout << hexagonal.back() << " ";

        while (hexagonal.back() > triangular.back()){
            generate_triangular(triangular);
        }

        cout << triangular.back() << " ";

        while (hexagonal.back() > pentagonal.back()){
            generate_pentagonal(pentagonal);
        }

        cout << pentagonal.back() << endl;
    }

    cout << hexagonal.back() << " ";

}