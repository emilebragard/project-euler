#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

#include "functions.h"

using namespace std;


int main() {

    int size = 1000000;

    vector<bool> is_prime = generate_primes(size);
    vector<int> primes;
    for (int i = 0; i < is_prime.size(); i++){
        if (is_prime[i]){
            primes.push_back(i);
        }
    }

    int most_primes = 0;
    int most_prime_sum = 0;

    int bottom_sum = 0;
    for (int i = 0; bottom_sum < size; i+= 2){
        if (i + 2 > most_primes){
            if (is_prime[bottom_sum]){
                most_primes = i+2;  
                most_prime_sum = bottom_sum;
            }
        }
        bottom_sum += primes[i] + primes[i+1];
    }

    
    bool max_primes = false;
    most_primes--;

    while (!max_primes){
        int start_index = 0;
        int current_sum = 0;

        while(!is_prime[current_sum]){
            current_sum = 0;
            for(int i = 0; i < most_primes + 2; i++){
                current_sum += primes[start_index + i];
                cout << primes[start_index + i] << " + ";
            }

            cout << " = " << current_sum << endl;
            start_index++;

            if (current_sum > size){
                if (start_index == 1){
                    max_primes = true;
                }
                break;
            }

        }

        if (current_sum < size){
            most_prime_sum = current_sum;
        }
        most_primes +=2;
        
    }


    cout << most_primes << " " << most_prime_sum;


}