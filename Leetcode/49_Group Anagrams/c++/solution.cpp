/*******************
Given an array of strings, group anagrams together.
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
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > dic;
        int n = strs.size();
        for(int i = 0; i < n; i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(dic.find(temp) != dic.end())
                dic[temp].push_back(strs[i]);
            else
                dic[temp] = {strs[i]};
        }
        vector<vector<string> > ans;
        for(auto iter = dic.begin(); iter != dic.end(); iter++)
            ans.push_back(iter->second);
        return ans;
    }
};

int main() {
    return 0;
}