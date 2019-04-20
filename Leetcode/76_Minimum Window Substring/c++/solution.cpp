/*******************
Given a string S and a string T, 
find the minimum window in S which will contain all the characters in T in complexity O(n).
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_map>
#include <limits.h>

using namespace std;

// 时间和空间都还可以优化
class Solution1 {
public:
    string minWindow(string s, string t) {
        string result;
        if(s.empty() || t.empty()){
            return result;
        }
        unordered_map<char, int> map;
        unordered_map<char, int> window;
        for(int i = 0; i < t.length(); i++){
            map[t[i]]++;
        }
        int minLength = INT_MAX;
        int letterCounter = 0;
        for(int slow = 0, fast = 0; fast < s.length(); fast++){
            char c = s[fast];
            if(map.find(c) != map.end()){
                window[c]++;
                if(window[c] <= map[c]){
                    letterCounter++;
                }
            }
            if(letterCounter >= t.length()){
                while(map.find(s[slow]) == map.end() || window[s[slow]] > map[s[slow]]){
                    window[s[slow]]--;
                    slow++;
                }
                if(fast - slow + 1 < minLength){
                    minLength = fast - slow + 1;
                    result = s.substr(slow, minLength);
                }
            }
        }
        return result;   
    }
};

class Solution2 {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c:t) map[c]++;
        int begin=0,end=0,head=0,d=INT_MAX,cnt=t.size();
        while(end < s.size()){
            //if(map[s[end++]]-->0) cnt--;
            if(map[s[end]] > 0) {
                cnt--;    
            }
            map[s[end]]--;
            end++;
            while(cnt==0){
                if(d>end-begin) d=end-(head=begin);
                // if(map[s[begin++]]++==0) cnt++;
                if(map[s[begin]] == 0) {
                    cnt++;
                }
                map[s[begin]]++;    
                begin++;   
            }
        }
        return d==INT_MAX ? "" : s.substr(head,d);
    }
};

int main() {
    return 0;
}