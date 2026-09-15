#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
    vector<long long int> word_lengths;
    word_lengths.push_back(0); 
    word_lengths.push_back(3); // one
    word_lengths.push_back(3); // two
    word_lengths.push_back(5); // three
    word_lengths.push_back(4); // four
    word_lengths.push_back(4); // five
    word_lengths.push_back(3); // six
    word_lengths.push_back(5); // seven
    word_lengths.push_back(5); // eight
    word_lengths.push_back(4); // nine
    word_lengths.push_back(3); // ten
    word_lengths.push_back(6); // eleven (6 letters)
    word_lengths.push_back(6); // twelve (6 letters)
    word_lengths.push_back(8); // thirteen (8 letters)
    word_lengths.push_back(8); // fourteen (8 letters)
    word_lengths.push_back(7); // fifteen (7 letters)
    word_lengths.push_back(7); // sixteen (7 letters)
    word_lengths.push_back(9); // seventeen (9 letters)
    word_lengths.push_back(8); // eighteen (8 letters)
    word_lengths.push_back(8); // nineteen (8 letters)

    word_lengths.push_back(6); // twenty (6 letters)
    for (int i = 1; i < 10; i++){
        word_lengths.push_back(6 + word_lengths[i]);
    }
    word_lengths.push_back(6); // thirty (6 letters)
    for (int i = 1; i < 10; i++){
        word_lengths.push_back(6 + word_lengths[i]);
    }
    word_lengths.push_back(5); // forty (5 letters)
    for (int i = 1; i < 10; i++){
        word_lengths.push_back(5 + word_lengths[i]);
    }
    word_lengths.push_back(5); // fifty (5 letters)
    for (int i = 1; i < 10; i++){
        word_lengths.push_back(5 + word_lengths[i]);
    }
    word_lengths.push_back(5); // sixty (5 letters)
    for (int i = 1; i < 10; i++){
        word_lengths.push_back(5 + word_lengths[i]);
    }
    word_lengths.push_back(7); // seventy (7 letters)
    for (int i = 1; i < 10; i++){
        word_lengths.push_back(7 + word_lengths[i]);
    }
    word_lengths.push_back(6); // eighty (6 letters)
    for (int i = 1; i < 10; i++){
        word_lengths.push_back(6 + word_lengths[i]);
    }
    word_lengths.push_back(6); // ninety (6 letters)
    for (int i = 1; i < 10; i++){
        word_lengths.push_back(6 + word_lengths[i]);
    }

    word_lengths.push_back(10); // one hundred (10 letters)
    for (int i = 101; i < 1000; i++){
        int count = 7; // hundred
        count += word_lengths[i/100]; // 100s place
        if (i % 100 > 0){
            count += 3; // and
        }
        count += word_lengths[i%100]; // tens/ones place

        word_lengths.push_back(count);

    }

    word_lengths.push_back(11); // one thousand (11 letters)

    int sum = 0;
    for (int wordlen : word_lengths){
        sum += wordlen;
    }

    cout << sum;
}