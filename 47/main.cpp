#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

#include "functions.h"

using namespace std;



int main() {

    vector<vector<int>> prime_factors = {{},{}};
    vector<bool> has_prime_factors = {false, false};
    vector<bool> is_prime = generate_primes(10000000);

    while (prime_factors.back().size() != 4 || prime_factors[prime_factors.size()-2].size() != 4 || prime_factors[prime_factors.size()-3].size() != 4  || prime_factors[prime_factors.size()-4].size() != 4){
        find_prime_factors(prime_factors, has_prime_factors, is_prime);
    }

    cout << prime_factors.size() - 4 << " " << prime_factors.size() - 3 << " " << prime_factors.size() - 2 << " " << prime_factors.size() - 1;

}