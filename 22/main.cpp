#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <sstream>
#include <map>
#include <string>

using namespace std;


int main() {
    ifstream file("names.txt");
    map<string, int> name_map;
    string name;

    if (!file) {
        cerr << "Unable to open file\n";
        return 1;
    }

     while (getline(file, name, ',')) {

        string final_name(name.begin()+1, name.end()-1);
        name_map.emplace(final_name, 0);
    }

    file.close();

    vector<string> sorted_names = {};

    for (const auto& pair : name_map){
        sorted_names.push_back(pair.first);
    }

    long long int sum = 0;

    for (int pos = 0; pos < sorted_names.size(); pos ++){
        int letter_val = 0;
        for (int letter = 0; letter < sorted_names[pos].length(); letter++){
            letter_val += int(sorted_names[pos][letter]) - 64;
        }
        sum += letter_val * (pos+1);

    }

    cout << sum;

    

    return 0;

}