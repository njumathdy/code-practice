/*******************
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.
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
    int longestPalindrome(string s) {
        if(s.size() < 2)
            return s.size();
        
        unordered_map<char, int> dic;
        for(auto c : s)
            dic[c]++;
        
        int res = 0, max_odd = 0;
        for(auto c : dic) {
            if(c.second % 2)
                max_odd = max(c.second, max_odd);
            res += c.second / 2 * 2;
        }
        if(max_odd > 0)
            res++;
        
        return res;
    }
};

int main() {
    return 0;
}