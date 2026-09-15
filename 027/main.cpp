#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    vector<int> primes;
    primes.push_back(2); primes.push_back(3);

    vector<bool> is_prime = {};
    for (int i = 0; i < pow(1000,2); i++){
        is_prime.push_back(false);
    }
    is_prime[2] = true; is_prime[3] = true;

    for(int i = 5; primes.back() < pow(1000,2); i = i + 2){
        bool prime = true;
        for (int j = 0; j < primes.size()-1; j++){
            if (i% primes[j] == 0){
                prime = false;
                break;}
            }
        
        if (prime){
        primes.push_back(i);
        is_prime[i] = true;
        }
    }



    vector<int> possible_Bs = {};
    for (int i = 0; primes[i] < 1000; i++){
        possible_Bs.push_back(primes[i]);
    }

    int max_product = 0; int max_a = 0; int max_b = 0;
    int max_primes = 0;

    cout << "Primes computed." << endl;

    for (int a = 0; a < 1000; a++){
        // Positive
        for (int b = 0; b < possible_Bs.size(); b++){
            int n = 0;
            while (is_prime[pow(n,2) + a*n + possible_Bs[b]]){
                n++;
            }
            if (n > max_primes){
                max_primes = n;
                max_product = a*possible_Bs[b];
                max_a = a; max_b = possible_Bs[b];
            }
        }
        // Negative
        for (int b = 0; b < possible_Bs.size(); b++){
            int n = 0;
            while ((pow(n,2) + (-1)*a*n + possible_Bs[b] > 0)&&(is_prime[pow(n,2) + (-1)*a*n + possible_Bs[b]])){
                n++;
            }
            if (n > max_primes){
                max_primes = n;
                max_product = a*possible_Bs[b];
                max_a = a*-1; max_b = possible_Bs[b];
            }
        }
    }

    cout << max_a << "*" << max_b << "= " << max_product << "- " << max_primes;
  
}