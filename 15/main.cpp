#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    int box_size = 20;
    vector<long long int> old_vector = {1};
    vector<long long int> new_vector;
    for (int i = 0; i < box_size; i++){
        new_vector.push_back(1);
        for(int j = 0; j < old_vector.size()-1; j++){
            new_vector.push_back(old_vector[j]+old_vector[j+1]);
        }
        new_vector.push_back(1);
        old_vector = new_vector;
        new_vector = {};
        for (int i = 0; i < old_vector.size(); i++){
            cout << old_vector[i] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < box_size; i++){
        for(int j = 0; j < old_vector.size()-1; j++){
            new_vector.push_back(old_vector[j]+old_vector[j+1]);
        }
        old_vector = new_vector;
        new_vector = {};
        for (int i = 0; i < old_vector.size(); i++){
            cout << old_vector[i] << " ";
        }
        cout << endl;
    }
    cout << old_vector[0];
}