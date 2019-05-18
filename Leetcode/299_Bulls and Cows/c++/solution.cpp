/*******************
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 

Please note that both secret number and friend's guess may contain duplicate digits.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        unordered_map<char, int> table;
        
        int n = secret.size();
        for(int i = 0; i < n; i++) {
            if(secret[i] == guess[i]) {
                bull++;
                continue;
            } 
            if(table.find(secret[i]) == table.end()) {
                table[secret[i]] = 1;
            } else
                table[secret[i]]++;
        }
        for(int i = 0; i < n; i++) {
            if(secret[i] == guess[i] || table.find(guess[i]) == table.end())
                continue;
            else {
                if(table[guess[i]] > 0) {
                    cow++;
                    table[guess[i]]--;
                }
            }
        }
        
        string res = "";
        res += (to_string(bull) + "A");
        res += (to_string(cow) + "B");
        
        return res;
    }
};

int main() {
    return 0;
}