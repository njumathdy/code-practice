/*******************
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> dict;
        
        if(s.length() != t.length()) return false;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(dict.count(s[i]) != 0)
            {
                if(dict[s[i]] != t[i]) return false;
            }
            else
            {
                for(auto it = dict.begin(); it != dict.end(); it++)
                {
                    if(it->second == t[i]) return false;                        
                }
            }
            dict[s[i]] = t[i];
        }
        
        return true;    
    }
};

int main() {
    return 0;
}