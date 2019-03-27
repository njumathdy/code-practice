/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size();
        int num = words.size();
        if(n <= 0 || num <= 0) return ans;
        
        int len = words[0].size();
        
        unordered_map<string, int> dict;
        
        for(int i = 0; i < num; i++)
            dict[words[i]]++;
        
        for(int i = 0; i < len; i++) {
            int left = i;
            int count = 0;
            unordered_map<string, int> tdict;
            for(int j = i; j <= n - len; j += len) {
                string str = s.substr(j, len);
                if(dict.count(str)) {
                    tdict[str]++;
                    if(tdict[str] <= dict[str])
                        count++;
                    else {
                        while(tdict[str] > dict[str]) {
                            string str1 = s.substr(left, len);
                            tdict[str1]--;
                            if(tdict[str1] < dict[str1]) 
                                count--;
                            left += len;
                        }
                    }
                    
                    if(count == num) {
                        ans.push_back(left);
                        tdict[s.substr(left, len)]--;
                        count--;
                        left += len;
                    }
                } else {
                    tdict.clear();
                    count = 0;
                    left = j + len;
                }
            }   
        }
        
        return ans;
    }
};

int main() {
    string s = "0123456789";
    string s1 = "abcdefghij";
    string s2 = "abc";
    cout << sizeof("0123456789") << " " << sizeof("abcdefghij") << endl;
    // string的实现在各库中可能有所不同，但是在同一库中相同一点是，无论你的string里放多长的字符串，它的sizeof()都是固定的，字符串所占的空间是从堆中动态分配的，与sizeof()无关。
    cout << sizeof('\0') << " " << sizeof(s1) << " " << sizeof(s) << " " << sizeof(s2) << endl;
    cout << s.length() << " " << s.size() << endl;
    cout << s.size() / s.length() << endl;

    return 0;
}