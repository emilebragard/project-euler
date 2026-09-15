#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    long long int number = 600851475143;
    int max_factor = sqrt(number)+1;
    vector<int> prime_factors;
    for (int i = 3; i < max_factor; i = i+2){
        bool prime = true;
        if (number % i == 0){
            if (prime_factors.size() > 0){
                for (int j = 0; j < prime_factors.size()-1; j++){
                    if (i% prime_factors[j] == 0){
                        prime = false;}
                }
                }
            if (prime){
            prime_factors.push_back(i);}
        }
    }

    cout << prime_factors.back();

    return 1;
}