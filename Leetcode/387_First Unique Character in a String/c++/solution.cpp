/*******************
Given a string, find the first non-repeating character in it and return it's index. 
If it doesn't exist, return -1.
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
    int firstUniqChar(string s) {
        if(s.empty())
            return -1;
        
        unordered_map<char, int> table;
        for(auto c : s) {
            if(table.find(c) == table.end())
                table[c] = 1;
            else
                table[c]++;
        }
        for(int i = 0; i < s.size(); i++) {
            if(table[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

int main() {
    return 0;
}