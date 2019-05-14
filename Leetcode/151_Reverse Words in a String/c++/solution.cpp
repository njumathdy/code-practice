/*******************
Given an input string, reverse the string word by word.
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
    string reverseWords(string s) {
        string res = s;
        int i=0, j=0;
        int l=0;
        int len=s.length();
        int wordcount=0;
        
        while(true){
            while(i<len && res[i] == ' ') i++;  // 跳过前面的空格
            if(i==len) break;
            if(wordcount) res[j++] = ' ';
            l=j;
            while(i<len && res[i] != ' ') {
                res[j] = res[i]; 
                j++; i++;
            } 
            reverseWord(res, l, j-1);
            wordcount++;   
        }
        
        res.resize(j);  
        reverseWord(res, 0, j-1); 
        return res;
    }
    
    void reverseWord(string& s, int i, int j) {
        while(i < j) {
            char t = s[i];
            s[i++] = s[j];
            s[j--] = t;
        }
    }
};

int main() {
    return 0;
}