/*******************
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.
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
    vector<vector<string> > partition(string s) {
        if(s.size() == 0)
            return {};
        
        vector<vector<string> > ans;
        vector<string> temp;
        
        dfs(0, s, ans, temp);
        
        return ans;
    }
    
    void dfs(int index, string s, vector<vector<string> >& ans, vector<string>& temp) {
        if(index == s.size())
            ans.push_back(temp);
        
        for(int i = index; i < s.size(); i++) {
            if(isPalindrome(s, index, i)) {
                temp.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, ans, temp);
                temp.pop_back();
            }
        }  
    }
    
    bool isPalindrome(const string& s, int begin, int end) {
        if(begin > end)
            return false;
        while(begin <= end) {
            if(s[begin++] != s[end--])
                return false;
        }
        return true;
    }
};

int main() {
    return 0;
}