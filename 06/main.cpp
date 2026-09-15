#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    int num = 100; int sum_to_num = 0; int difference = 0;
    for (int i = 0; i <= num; i++){
        difference -= pow(i, 2);
        sum_to_num += i;
    }
    difference += pow(sum_to_num, 2);

    cout << difference;

    return 1;
}