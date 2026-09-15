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

class Spiral{
    public:

        void generate(){
            for (int i = nums.back()+2; nums.size() < 2*grid_length - 1; i++){
                if ((i-1) % diagonal_divisor == 0){
                    nums.push_back(i);
                }
                if ((i-1) == row_indicator*8){
                    row_indicator+= ri_increment; ri_increment++;
                    diagonal_divisor += 2;
                }
            }
        }

        Spiral() : grid_length(7), diagonal_divisor(2), row_indicator(1), ri_increment(2) {
            nums = {1};
            generate();
        }


        void extend(int length_addition){
            grid_length += length_addition;
            generate();
        }

        int grid_length;
        vector<int> nums;
    private:
        

        int diagonal_divisor;
        int row_indicator;
        int ri_increment;

};






int main() {
    
    vector<bool> is_prime = generate_primes(1000000000);

    double desired_percent = 10.0;
    double current_percent = 100.0;

    Spiral spiral;

    while (desired_percent < current_percent){
        double diag_count = spiral.nums.size();
        double prime_diags = 0;
        for (int num : spiral.nums){
            if (is_prime[num]) prime_diags++;
        }
        current_percent = (prime_diags / diag_count) * 100.0;

        int side_addition = (10.0 * prime_diags - diag_count)/4;
        if (side_addition % 2 == 1) side_addition--;
        if (side_addition < 2) side_addition = 2;

        cout << spiral.grid_length << " " << current_percent << endl;
        spiral.extend(side_addition);
        
    }

    return 0;
}
