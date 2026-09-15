#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    for (int a = 1; a < 998; a++){
        for (int b = 1; b < 998; b++){
            int c = 1000 - a - b;
            if (pow(a,2) + pow(b,2) == pow(c,2)){
                cout << a << " " << b << " " << c;
                cout << endl << a*b*c;
                return 1;
            }
        }
    }

}