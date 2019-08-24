/*******************
Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s. 
In particular, your input is the string p and you need to output the number of different non-empty substrings of p in the string s.
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
    int findSubstringInWraproundString(string p) {
        if(p.size() < 2)
            return p.size();
        
        vector<int> count(26, 0);
        
        int maxl = 0;
        for(int i = 0; i < p.size(); i++) {
            if(i > 0 && (p[i] - p[i-1] == 1 || p[i-1] - p[i] == 25)) {
                maxl++;
            } else
                maxl = 1;
            
            count[p[i] - 'a'] = max(count[p[i]-'a'], maxl);
        }
        
        int res = 0;
        for(auto num : count)
            res += num;
        
        return res;
    }
};

int main() {
    return 0;
}