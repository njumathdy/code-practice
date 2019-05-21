/*******************
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.
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
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size())
            return false;
        
        unordered_map<char, int> table;
        for(auto c : magazine) {
            if(table.find(c) == table.end())
                table[c] = 1;
            else
                table[c]++;
        }
        for(auto c : ransomNote) {
            if(table.find(c) == table.end())
                return false;
            else {
                table[c]--;
                if(table[c] < 0)
                    return false;
            }
        }
        
        return true;
    }
};

int main() {
    return 0;
}