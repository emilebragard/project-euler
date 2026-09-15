#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <sstream>
#include <map>
#include <string>
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

unsigned long long int vec_to_int(const vector<int>& vec){
    unsigned long long int num = 0;
    for (int a = vec.size()-1; a >= 0; a--){
        num += vec[a]* pow(10, vec.size()-a-1);
    }
    return num;
}

void find_combos(int size, vector<int> potential_digits, vector<int> currentnum, vector<vector<int>>& combos, bool allow_repeats){
    for (int i = 0; i < potential_digits.size(); i++){
        vector<int> new_num = currentnum;
        new_num.push_back(potential_digits[i]);
        
        vector<int> new_digits = potential_digits;
        if (!allow_repeats){
        new_digits.erase(new_digits.begin() + i);}

        if (new_num.size() == size){
            int digit_sum = 0;
            for (int num : new_num){
                digit_sum += num;
            }
            if (new_num.back() != 5 && new_num.back() % 2 != 0 && digit_sum % 3 != 0){
                combos.push_back(new_num);
            }
        }
        else{
            find_combos(size, new_digits, new_num, combos, allow_repeats);
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
    return max_num;
}

int main() {
    ifstream file("words.txt");
    vector<string> words;
    string word;

    if (!file) {
        cerr << "Unable to open file\n";
        return 1;
    }

     while (getline(file, word, ',')) {

        string final_word(word.begin()+1, word.end()-1);
        words.push_back(final_word);
    }

    file.close();

    vector<int> word_vals;

    for (int pos = 0; pos < words.size(); pos ++){
        int word_val = 0;
        for (int letter = 0; letter < words[pos].length(); letter++){
            word_val += int(words[pos][letter]) - 64;
        }
        word_vals.push_back(word_val);

    }
    
    vector<int> trianglenums;
    trianglenums.push_back(0), trianglenums.push_back(1);
    while (trianglenums.back() < find_max(word_vals)){
        trianglenums.push_back(trianglenums.back()+trianglenums.size());
    }

    int triangle_words = 0;

    for (int word_val : word_vals){
        if (find(trianglenums.begin(),trianglenums.end(), word_val) != trianglenums.end()){
            triangle_words++;
        }
    }

    cout << triangle_words;

    return 0;

}