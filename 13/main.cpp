#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <sstream>

using namespace std;


int main() {
    ifstream file("numlist.txt");
    vector<vector<int>> all_digits;
    string number;

    if (!file) {
        cerr << "Unable to open file\n";
        return 1;
    }

    while (getline(file, number)) {
        vector<int> digits;
        for (char digit_char : number) {
            if (isdigit(digit_char)) {
                int digit = digit_char - '0'; // Convert char to int
                digits.push_back(digit);
            }
        }
        all_digits.push_back(digits);
    }

    vector<int> final_num;
    int carry_over = 0;
    int current_sum = 0;

    for (int i = 0; i < 50; i++){
    int current_sum = carry_over;
    carry_over = 0;
    
    for (vector<int> digitlist : all_digits){
        current_sum += digitlist[49-i];
    }
    carry_over = current_sum / 10;
    if (i<49){
    final_num.push_back(current_sum %10);}
    else{ final_num.push_back(current_sum);}
    }


    for(int i = final_num.size()-1; i >=0; i--){
        cout << final_num[i];
    }
}