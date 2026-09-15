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

struct Card {
    int value;  // 2-14, where T = 10, J = 11, Q = 12, K = 13, A = 14
    char suit;  // 'H', 'D', 'C', 'S' for Hearts, Diamonds, Clubs, Spades
};

struct Hand {
    vector<Card> cards;
};

struct HandValue{
    string type;
    int num1; // first pair/triple value
    int num2; // second pair if two pair or full house
    vector<int> high_nums; // number not part of the pairs/triple, or all the nums in a straight (sorted high->low)
};

int convertToNumericValue(char ch) {
    if (ch >= '2' && ch <= '9') {
        return ch - '0';  // Convert char to int
    }

    unordered_map<char, int> values = {
        {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}
    };

    return values[ch];
};



HandValue handvalue(Hand hand){
    HandValue value;
    value.type = "highnum";
    value.num1 = 0; value.num2 = 0;
    // Determine whether it is a flush
    bool flush = true;
    char suit1 = hand.cards[0].suit;
    for (Card card : hand.cards){
        if (card.suit != suit1){
            flush = false; break;
        }
    }
    if (flush) value.type = "flush";

    // We no longer care about the suit, so we can just reference a vector of the card values
    vector<int> card_values;
    for (Card card : hand.cards) card_values.push_back(card.value);
    sort(card_values.begin(),card_values.end());
    reverse(card_values.begin(), card_values.end());

    vector<int> repeat_nums;
    if (!flush){
        // Check for pairs+
        
        for (int i = 0; i < card_values.size()-1; i++){
            if (card_values[i] == card_values[i+1]) repeat_nums.push_back(card_values[i]);
        }

        if (repeat_nums.size() != 0){
            if (repeat_nums.size() == 1){
                value.type = "pair";
                value.num1 = repeat_nums[0];
                removeElement(card_values, repeat_nums[0]);
            }
            else if (repeat_nums.size() == 2){
                // Two pair
                if (repeat_nums[0] != repeat_nums[1]){
                    value.type = "twopair";
                    value.num1 = repeat_nums[0];
                    value.num2 = repeat_nums[1];
                    removeElement(card_values, repeat_nums[0]);
                    removeElement(card_values, repeat_nums[1]);
                }
                // Three of a king
                else{
                    value.type = "3ofakind";
                    value.num1 = repeat_nums[0];
                    removeElement(card_values, repeat_nums[0]);
                }
            }
            else{
                if (repeat_nums[0] == repeat_nums[1] && repeat_nums[1] == repeat_nums[2]){
                    value.type = "4ofakind";
                    value.num1 = repeat_nums[0];
                    removeElement(card_values, repeat_nums[0]);
                }
                else{
                    value.type = "fullhouse";
                    if (repeat_nums[0] == repeat_nums[1]){
                        value.num1 = repeat_nums[0];
                        value.num2 = repeat_nums[2];
                    }
                    else{
                        value.num1 = repeat_nums[2];
                        value.num2 = repeat_nums[0];
                    }
                    card_values = {};
                }
            }
        }
    }

    if (repeat_nums.size() == 0){
        //Check for straights
        bool straight = true;
        int start = card_values[0];
        for (int i = 0; i < card_values.size(); i++){
            if (card_values[i] != start-i){
                straight = false;
                break;
            }
        }

        if (straight){
            if (flush) value.type = "straightflush";
            else value.type = "straight";
        }
    }

    value.high_nums = card_values;

    return value;
};


int main() {
    string filename = "poker.txt";
    ifstream file(filename);

    vector<pair<Hand, Hand>> hands;

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            Hand hand1, hand2;
            Card card;
            char valueChar;

            // Read first 5 cards for Player 1
            for (int i = 0; i < 5; ++i) {
                iss >> valueChar >> card.suit;
                card.value = convertToNumericValue(valueChar);
                hand1.cards.push_back(card);
            }

            // Read next 5 cards for Player 2
            for (int i = 0; i < 5; ++i) {
                iss >> valueChar >> card.suit;
                card.value = convertToNumericValue(valueChar);
                hand2.cards.push_back(card);
            }
            hands.push_back(make_pair(hand1, hand2));
        }
        file.close();
    } else {
        cerr << "Could not open file: " + filename << endl;
    }

    // 'hands' contains all the pairs of hands from the file
    // We now have all hands stored in their respective files

    unordered_map<string, int> hand_num_values = {
        {"highnum", 0}, {"pair", 1}, {"twopair", 2}, {"3ofakind", 3}, {"straight", 4}, {"flush", 5},
        {"fullhouse", 6}, {"4ofakind", 7}, {"straightflush", 8}
    };

    int player1_wins = 0;

    for (pair<Hand,Hand> handpair : hands){
        HandValue h1_val = handvalue(handpair.first);
        HandValue h2_val = handvalue(handpair.second);
        int h1_num_val = hand_num_values[h1_val.type];
        int h2_num_val = hand_num_values[h2_val.type];

        vector<int> h1_smart_val = {h1_num_val, h1_val.num1, h1_val.num2};
        for (int val : h1_val.high_nums){
            h1_smart_val.push_back(val);
        }
        vector<int> h2_smart_val = {h2_num_val, h2_val.num1, h2_val.num2};
        for (int val : h2_val.high_nums){
            h2_smart_val.push_back(val);
        }

        for (int i = 0; i < h1_smart_val.size() && i < h2_smart_val.size(); i++){
            if (h1_smart_val[i] > h2_smart_val[i]){
                player1_wins++;
                break;
            }
            else if (h1_smart_val[i] < h2_smart_val[i]){
                break;
            }
        }

    }
    cout << player1_wins;

    

    return 0;
}
