#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <numeric>

#include "functions.h"

using namespace std;

int main() {

    int lychrel_count = 0;
    
    for (int n = 1; n < 10000; n++){
        bool lychrel = true;
        vector<int> current = int_to_vec(n);

        for (int i = 0; i < 50; i++){
                    
            next_lychrel(current);

            if (is_palindromic(current)){
                    lychrel = false;
                    break;
                }
            }
        if (lychrel) lychrel_count++;
    }

    cout << lychrel_count;

    return 0;
}
