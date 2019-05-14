/*******************
Given two strings s and t , write a function to determine if t is an anagram of s.
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
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        unordered_map<char, int> dict;
        for(auto c : s) {
            if(dict.find(c) == dict.end())
                dict[c] = 1;
            else
                dict[c]++;
        }
        for(auto c : t) {
            if(dict.find(c) == dict.end())
                return false;
            else
                dict[c]--;
        }
        for(auto iter = dict.begin(); iter != dict.end(); iter++) {
            if(iter -> second != 0)
                return false;
        }
        
        return true;
    }
};

int main() {
    return 0;
}