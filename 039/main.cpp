#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

vector<bool> generate_perfect_squares(int max){

    vector<bool> perfect_square(pow(max + 10, 2), false);

    for (int i = 1; i <= max; i++){
        perfect_square[pow(i,2)] = true;
    }

    return perfect_square;
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

vector<int> int_to_vec(const int num){
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
    vec.erase(std::remove(vec.begin(), vec.end(), element), vec.end());
}


int main() {

    int max_sqrt_num = 1000;

    vector<bool> is_square = generate_perfect_squares(max_sqrt_num);

    map<int,int> squared;
    for (int i = 1; i <= max_sqrt_num; i++){
        squared[i] = pow(i,2);
    }

    // Find all right triangles
    vector<int> num_of_right_triangles(max_sqrt_num, 0);

    for (int i = 1; i < max_sqrt_num; i++){
        for (int j = i; j < max_sqrt_num; j++){
            int perimeter = i + j + sqrt(squared[i] + squared[j]);
            if (perimeter <= 1000){
                if (is_square[squared[i] + squared[j]]){
                    cout << i << " " << j << " " << sqrt(squared[i] + squared[j]) << endl;
                    num_of_right_triangles[perimeter]++;
                }
            }
        }
    }

    cout << find_max(num_of_right_triangles);

}