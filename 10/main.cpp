#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    vector<int> primes;
    primes.push_back(2); primes.push_back(3);

    for(int i = 5; primes.back() < 2000000; i = i + 2){
        bool prime = true;
            for (int j = 0; j < primes.size()-1; j++){
                if (i% primes[j] == 0){
                    prime = false;
                    break;}
                }
            
            if (prime){
            primes.push_back(i);}
    }

    primes.pop_back();
    long long int sum = 0;
    for (int prime : primes){
        sum += prime;
    }
    cout << sum;
  
}