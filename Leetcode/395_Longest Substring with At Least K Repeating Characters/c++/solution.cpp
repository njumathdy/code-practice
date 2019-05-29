/*******************
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.
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

// divide and conquer
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() < k)
            return 0;
        
        int n = s.size();
        unordered_map<char, int> count;
        for (char c : s) ++count[c];
        
        int mid = 0;
        while (mid < n && count[s[mid]] >= k) 
            ++mid;
        if (mid == n) return n;
        int left = longestSubstring(s.substr(0, mid), k);
        while (mid < n && count[s[mid]] < k) 
            ++mid;
        if(mid == n)
            return left;
        
        int right = longestSubstring(s.substr(mid), k);
        return max(left, right);
    }   
};

int main() {
    return 0;
}