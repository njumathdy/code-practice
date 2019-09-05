/*******************
Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string.
In one operation, you can choose any character of the string and change it to any other uppercase English character.
Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.
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
    int characterReplacement(string s, int k) {
        int size = s.size(); int ret = 0;
        vector<int> count(26, 0);
        int start = 0; int end = 0; int globalMaxFreq = 0; 
        for(; end<size; end++){
            count[s[end]-'A'] += 1;
            globalMaxFreq = max(globalMaxFreq, count[s[end]-'A']);
            if((end-start+1)-globalMaxFreq > k) {
                ret = max(ret, (end-start));
                count[s[start]-'A'] -= 1;
                start += 1;
            }
        }
        return max(ret, end-start);
    }
};

int main() {
    return 0;
}