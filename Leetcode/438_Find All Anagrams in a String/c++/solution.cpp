/*******************
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size())
            return {};
        
        vector<int> snum(26, 0), pnum(26, 0), ans;
        int m = s.size(), n = p.size();
        for(int i = 0; i < n; i++) {
            snum[s[i]-'a']++;
            pnum[p[i]-'a']++;
        }
        if(snum == pnum)
            ans.push_back(0);
        for(int i = n; i < m; i++) {
            snum[s[i]-'a']++;
            snum[s[i-n]-'a']--;
            if(snum == pnum)
                ans.push_back(i-n+1);
        }
        
        return ans;
    }   
};

int main() {
    return 0;
}