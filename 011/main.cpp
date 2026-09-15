#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <sstream>

using namespace std;


int main() {
    ifstream file("numlist.txt");
    vector<int> numbers;
    string line;

    if (!file) {
        cerr << "Unable to open file\n";
        return 1;
    }

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int number;
        while (iss >> number) {
            numbers.push_back(number);
            cout << number << " ";
        }
        cout << endl;
    }

    long long int max_product = 0;

    
    
    for (int i = 0; i < numbers.size() - 3; i++){
        //Horizontal
        if (i % 20 < 18){
            long long int current_prod = 1;
            for (int j = 0; j < 4; j++){
                current_prod *= numbers[i+j];
            }
            if (current_prod > max_product){
                max_product = current_prod;
            }
        }
        //Vertical
        if (i < 340){
            long long int current_prod = 1;
            for (int j = 0; j < 80; j = j+20){
                current_prod *= numbers[i+j];
            }
            if (current_prod > max_product){
                max_product = current_prod;
            }
        }
        //Diagonal Right
        if ((i < 340)&&(i%20 < 17)){
            long long int current_prod = 1;
            for (int j = 0; j < 80; j = j+21){
                current_prod *= numbers[i+j];
            }
            if (current_prod > max_product){
                max_product = current_prod;
            }
        }
        //Diagonal Left
        if ((i < 340)&&(i%20 > 2)){
            long long int current_prod = 1;
            for (int j = 0; j < 60; j = j+19){
                current_prod *= numbers[i+j];
            }
            if (current_prod > max_product){
                max_product = current_prod;
            }
        }
    }

    cout << max_product;
    
}