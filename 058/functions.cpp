#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

vector<int> int_to_vec(const int num){
    if (num == 0){return {0};}
    vector<int> num_vec;
    int altered_num = num;
    while (altered_num > 0){
        num_vec.push_back(altered_num % 10);
        altered_num = altered_num / 10;
    }
    reverse(num_vec.begin(),num_vec.end());
    return num_vec;
}

int vec_to_int(const vector<int>& vec){
    int num = 0;
    for (int a = vec.size()-1; a >= 0; a--){
        num += vec[a]* pow(10, vec.size()-a-1);
    }
    return num;
}

void removeElement(std::vector<int>& vec, int element) {
    while (find(vec.begin(), vec.end(), element) != vec.end())
    vec.erase(std::remove(vec.begin(), vec.end(), element), vec.end());
}

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

void permutations(int size, vector<int> potential_digits, vector<int> currentnum, vector<vector<int>>& combos, bool allow_repeats){

    for (int i = 0; i < potential_digits.size(); i++){
        vector<int> new_num = currentnum;
        new_num.push_back(potential_digits[i]);
        
        vector<int> new_digits = potential_digits;
        if (!allow_repeats){
        new_digits.erase(new_digits.begin() + i);}

        if (new_num.size() == size ){
            if (new_num[0] != 0){
                combos.push_back(new_num);
            }
            
        }
        else{
            permutations(size, new_digits, new_num, combos, allow_repeats);
        }
    }
}

int find_max(vector<int> vec){
    int max_num = 0;
    int max_pos = -1;
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] > max_num){
            max_num = vec[i];
            max_pos = i;
        }
    }
    return max_pos;
}

vector<int> vec_multiply(const vector<int> vec1, const vector<int> vec2){
    vector<int> answer_vec;
    vector<int> a = vec1; vector<int> b = vec2;
    reverse(a.begin(),a.end()); reverse(b.begin(), b.end());
    for (int i = 0; i < a.size() + b.size(); i++){
        answer_vec.push_back(0);
    }
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < b.size(); j++){
            int current_digit = answer_vec[i+j] + a[i]*b[j];
            answer_vec[i+j] = current_digit % 10;
            answer_vec[i+j+1] += current_digit / 10;
        }
    }

    while (answer_vec.back() == 0){
        answer_vec.pop_back();
    }

    reverse(answer_vec.begin(),answer_vec.end());
    return answer_vec;
}

vector<int> vec_add(const vector<int> vec1, const vector<int> vec2){
    vector<int> a = vec1; vector<int> b = vec2;
    reverse(a.begin(),a.end()); reverse(b.begin(), b.end());    
    vector<int> sum;
    int carry = 0;
    while (a.size() < b.size()){a.push_back(0);}
    while (b.size() < a.size()){b.push_back(0);}

    for (int i = 0; i < a.size(); i ++){
        sum.push_back((a[i] + b[i] + carry) % 10);
        carry = (a[i] + b[i] + carry) / 10;
    }

    if (carry > 0)  sum.push_back(carry);
    reverse(sum.begin(),sum.end());

    return sum;
}

vector<int> vec_subtract(const vector<int> larger, const vector<int> smaller){
    vector<int> larger1 = larger; vector<int> smaller1 = smaller;
    
    reverse(larger1.begin(),larger1.end()); reverse(smaller1.begin(), smaller1.end());
    for (int i = 0; i < smaller1.size(); i++){
        larger1[i] = larger1[i] - smaller1[i];
        if (larger1[i] < 0){
            larger1[i] += 10;
            larger1[i+1] --;
        }
    }
    while (larger1.back() == 0){larger1.pop_back();}
    
    reverse(larger1.begin(),larger1.end());
    return larger1;
}

vector<int> factorial (int number){
    vector<int> output = {1};
    for (int i = 2; i <= number; i ++){
        output = vec_multiply(output, int_to_vec(i));
    }
    return output;
}

bool greater_or_equal_to(vector<int> num1, vector<int> num2){
    if (num1.size() != num2.size()){
        if (num1.size() > num2.size()) return true;
        else return false;
    }
    else{
        for (int i = 0; i < num1.size(); i++){
            if (num1[i] != num2[i]){
                if (num1[i] > num2[i]) return true;
                else return false;
            }
        }
        return true;
    }
}


vector<int> vec_divide (const vector<int> dividend, const vector<int> divisor){
    
    vector<int> quotient; vector<int> remainder; int temp = 0;

    for (int pos = 0; pos < dividend.size(); pos++){
        remainder.push_back(dividend[pos]);
        while (greater_or_equal_to(remainder,divisor)){
            remainder = vec_subtract(remainder, divisor);
            temp++;
        }
        quotient.push_back(temp);
        temp = 0;
    }

    while (quotient[0] == 0){
        quotient = {quotient.begin()+1,quotient.end()};
    }

    return quotient;

}

vector<int> nCk(int n, int k){
    vector<int> numerator = factorial(n);
    vector<int> denominator = vec_multiply(factorial(k), factorial(n-k));
    return vec_divide(numerator,denominator);
}

bool is_palindromic(vector<int> num){
    bool palindrome = true;
    
    for (int i = 0; i <= num.size()-1; i++){
        if (num[i] != num[num.size() - 1 - i]){
            palindrome = false;
            break;
        }
    }
    return palindrome;
}

void next_lychrel(vector<int>& current){
    vector<int> flipped = current;
    reverse(flipped.begin(),flipped.end());
    current = vec_add(current,flipped);
}

int digit_sum(vector<int> num){
    int sum = 0;
    for (int digit : num){
        sum += digit;
    }
    return sum;
}

vector<int> power(vector<int> base, int exponent) {
    vector<int> result = {1}; 
    while (exponent > 0) {
        if (exponent % 2 == 1) { 
            result = vec_multiply(result, base);
        }
        base = vec_multiply(base, base);
        exponent /= 2;
    }
    return result;
}




