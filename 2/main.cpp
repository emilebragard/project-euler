#include <iostream>
#include <vector>

using namespace std;


int main() {
    int sum = 0;
    vector<int> fib_list;
    fib_list.push_back(1); fib_list.push_back(2);
    while (fib_list.back() < 4000000){
        fib_list.push_back(fib_list[fib_list.size()-2] + fib_list[fib_list.size()-1]);
    }
    fib_list.pop_back();
    for (int i = 1; i < fib_list.size(); i = i+3){
        sum = sum + fib_list[i];
    }

    cout << sum;

    return 1;
}