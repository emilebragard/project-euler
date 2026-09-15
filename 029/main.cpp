#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    vector<vector<int>> distinct_terms;

    for (int a = 2; a <= 100; a++){
        cout << "Working " << a << endl;
        for (int b = 2; b <= 100; b++){
            vector<int> number = {};
            number.push_back(a%10);
            if ((a/10)%10 > 0){number.push_back((a/10)%10);}
            if (a/100 > 0){number.push_back(a/100);}
            for (int i = 2; i <= b; i++){

                int carry = 0;

                for (int j = 0; j < number.size(); j++){
                    int multiplied = a*number[j] + carry;
                    carry = multiplied / 10;
                    number[j] = multiplied % 10;
                }

                while (carry > 0){ number.push_back(carry%10); carry = carry /10;}
            }

            bool in_list = false;
            for (vector<int> listnum : distinct_terms){
                if (listnum.size() == number.size()){
                    if (listnum == number){
                        in_list = true;
                    }
                }
            }
            if (!in_list){
                distinct_terms.push_back(number);
            }
        }
    }

    cout << endl << distinct_terms.size();

}