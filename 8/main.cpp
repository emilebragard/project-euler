#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    ifstream file("number.txt");
    vector<int> digits;
    string line;

    if (!file) {
        cerr << "Unable to open file\n";
        return 1;
    }

    while(getline(file,line)){
        for (char digit : line){
            if (isdigit(digit)){
                digits.push_back(digit - '0');
            }
        }
    }

    int consecutive_num = 13; long long int max_product = 0;
    for (int i = 0; i < 1000 - consecutive_num; i++){
        long long int current_prod = 1;
        for (int j = 0; j < consecutive_num; j++){
            current_prod *= digits[i+j];
        }
        if (current_prod > max_product){
            max_product = current_prod;
        }
    }

    cout << max_product;

}