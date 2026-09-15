#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    vector<long long int> trianglenums;
    int divnum = 500;
    trianglenums.push_back(0), trianglenums.push_back(1);
    bool found = false;
    while (!found){
        int div_count = 0;
        trianglenums.push_back(trianglenums.back()+trianglenums.size());
        cout << endl << trianglenums.back() << " ";
        if (trianglenums.back() % int(sqrt(trianglenums.back())) == 0){
            div_count += 1;
        }
        for (int i = sqrt(trianglenums.back()); i > 0; i--){
            if (trianglenums.back() % i == 0){
                div_count += 2;
            }
            if (i < (divnum - div_count)/2){
                break;
            }
        }
        if (div_count > divnum){
            found = true;
            cout << endl << trianglenums.back() << " "<< div_count;
        }
    }
    
}