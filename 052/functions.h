#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
using namespace std;


vector<int> int_to_vec(const int num);

int vec_to_int(const vector<int>& vec);

void removeElement(std::vector<int>& vec, int element);

vector<bool> generate_primes(unsigned long long int max);

void permutations(int size, vector<int> potential_digits, vector<int> currentnum, vector<vector<int>>& combos, bool allow_repeats);

int find_max(vector<int> vec);

vector<int> vec_multiply(const vector<int> vec1, const vector<int> vec2);

vector<int> vec_sum (const vector<int> vec1, const vector<int> vec2);


#endif // FUNCTIONS_H