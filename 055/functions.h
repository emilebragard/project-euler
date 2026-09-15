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

vector<int> vec_add(const vector<int> vec1, const vector<int> vec2);

vector<int> vec_subtract(const vector<int> larger, const vector<int> smaller);

vector<int> factorial (int number);

bool greater_or_equal_to(vector<int> num1, vector<int> num2);

vector<int> vec_divide (vector<int> num, vector<int> denom);

vector<int> nCk(int n, int k);

bool is_palindromic(vector<int> num);

void next_lychrel(vector<int>& current);

#endif // FUNCTIONS_H