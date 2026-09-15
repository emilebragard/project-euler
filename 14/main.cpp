#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    vector<long long int> collatz_length;
    long long int max_length = 0;
    int max_pos;
    collatz_length.push_back(0); collatz_length.push_back(1);
    for (int i = 2; i < 1000000; i++){
        long long int current = i;
        long long int count = 0;
        while (current >= collatz_length.size()){
        if (current % 2 == 0){
            current = current / 2;
        }
        else{
            current = 3*current + 1;
        }
        count += 1;
        }
        count += collatz_length[current];
        if (count > max_length){max_length = count; max_pos = i;}
        collatz_length.push_back(count);
    }

    cout << max_pos << ": " << max_length;
}