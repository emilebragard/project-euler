#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

using namespace std;

vector<bool> generate_primes(unsigned long long int max){

    vector<bool> is_prime(max + 1, true);
    is_prime[0] = false; is_prime[1] = false;

    for (unsigned long long int i = 2; i <= max; i++){
        if (is_prime[i]){
            for (unsigned long long int j = i; i*j <= max; j++){
                is_prime[i*j] = false;
            }
        }
    }

    return is_prime;
}

void generate_squares(vector<int>& squares){
    squares.push_back(pow(squares.size(),2));
}

int main() {

    vector<bool> is_prime = generate_primes(10000);

    vector<int> squares = {0};

    bool sum_works = true;

    int number = 0;

    for (int i = 9; sum_works; i += 2){
        number = i;
        // If i is composite
        if (!is_prime[i]){
            sum_works = false;
            for (int j = 2; j < i; j ++){
                if (is_prime[j]){
                    while (squares.back() < i){
                        generate_squares(squares);
                    }
                    for (int num = 1; (squares[num]*2) <= (i-j) ; num++){
                        if (j + 2*squares[num] == i){
                            // cout << i << " = " << j << " + 2 x " << num << "^2" << endl;
                            sum_works = true;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << number;
   

}