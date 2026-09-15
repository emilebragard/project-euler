#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <sstream>

using namespace std;


int main() {
    ifstream file("numlist.txt");
    vector<vector<int>> number_list;
    string line;

    if (!file) {
        cerr << "Unable to open file\n";
        return 1;
    }

    while (getline(file, line)) {
        istringstream iss(line);
        std::vector<int> line_numbers;
        int number;

        while (iss >> number) {
            line_numbers.push_back(number);
        }

        number_list.push_back(line_numbers);
    }

    file.close();

    while (number_list.size() > 1){
        int second_to_last = number_list.size()-2;
        for (int i = 0; i < number_list[second_to_last].size(); i++){
            int biggest = number_list.back()[i];
            if (number_list.back()[i+1] > biggest){
                biggest = number_list.back()[i+1];
            }
            number_list[second_to_last][i] += biggest;
        }
        number_list.pop_back();
    }

    cout << number_list[0][0];

    return 0;

}