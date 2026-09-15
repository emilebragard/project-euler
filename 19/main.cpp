#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    int start_weekday = 4; // Mar 1, 1901 was a Thursday
    long long int first_sun_count = 0;

    vector<int> sun_count = {2,2,2,1,2,1,2};

    for (int i = 1902; i < 2000; i++){
        first_sun_count += sun_count[start_weekday];
        start_weekday++;
        if (i % 4 == 0){
            start_weekday++;
        }
        start_weekday = start_weekday % 7;
    }
    
    sun_count = {2,2,1,1,2,1,1}; // update to avoid including jan/feb 2001
    first_sun_count += sun_count[start_weekday];

    cout << first_sun_count;

}