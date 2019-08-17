/*******************
Given a string s, find the longest palindromic substring in s. 
You may assume that the maximum length of s is 1000.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution1 {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2)
            return s;
        
        int n = s.size();
        string res;
        vector<vector<bool> > p(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++)
            p[i][i] = true;
        for(int i = 0; i < n-1; i++) {
            if(s[i] == s[i+1])
                p[i][i+1] = true;
        }
        for(int k = 2; k < n; k++) {
            for(int i = 0; i+k < n; i++) {
                if(s[i] == s[i+k])
                    p[i][i+k] = p[i+1][i+k-1];   
            }
        }
        for(int k = n-1; k >= 0; k--) {
            for(int i = 0; i+k < n; i++) {
                if(p[i][i+k]) {
                    res = s.substr(i,k+1);
                    break;
                }
            }
            if(!res.empty())
                break;
        }
        
        return res;      
    }
};

class Solution2 {
public:    
    string longestPalindrome(string s) {
        if(s.size() < 2)
            return s;
            
        int len = s.size();
        int maxLeft = 0, maxLen = 1;
        int start = 0;
        
        while(start < len) {
            if(len - start <= maxLen / 2)
                break;
            
            int l = start, r = start;
            
            while(r < len-1 && s[r + 1] == s[r])
                r++;
            start = r + 1;
            
            while(r < len - 1 && l > 0 && s[r + 1] == s[l - 1]) {
                r++;
                l--;
            }
               
            if(maxLen < (r - l + 1) ) {
                maxLeft = l;
                maxLen = r - l + 1;
            }
        }
        return s.substr(maxLeft, maxLen);
    }
};

int main() {
    return 0;
}