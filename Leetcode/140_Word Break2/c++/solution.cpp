/*******************
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    unordered_map<string, vector<string> > m;

    vector<string> combine(string word, vector<string> prev){
        for(int i = 0;i < prev.size();++i){
            prev[i] += " " + word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if(m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if(dict.count(s)){ //a whole string is a word
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word = s.substr(i);
            if(dict.count(word)){
                string rem = s.substr(0,i);
                vector<string> prev = combine(word,wordBreak(rem,dict));
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }
        m[s]=result; //memorize
        return result;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return wordBreak(s, dict);
    }
};

int main() {
    return 0;
}