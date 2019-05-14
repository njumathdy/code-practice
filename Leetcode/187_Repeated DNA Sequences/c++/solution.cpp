/*******************
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_map>
#include <bitset>

using namespace std;

// simple hashtable without any optimization
class Solution1 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.size() < 10)
            return ans;
        unordered_map<string, int> dict;
        for(int i = 0; i <= s.size() - 10; i++) {
            if(dict.find(s.substr(i, 10)) == dict.end()) {
                dict[s.substr(i, 10)] = 1;
            } else {
                dict[s.substr(i, 10)]++;
                if(dict[s.substr(i, 10)] == 2)
                    ans.push_back(s.substr(i, 10));
            }
        }
        return ans;
    }
};

// Leetcode solution
// 从两方面进行优化：用两个二进制位来表示每个字符，用20个二进制位表示一个长度为10的字符串
// 用bitset作为hashtable
class Solution2 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10)
            return vector<string>();
        
        vector<string> R;
        bitset<1<<20> S1;
        bitset<1<<20> S2;
    
        int val = 0;
        for (int i=0; i < 10; i++)   // Calc the hash value for the first string.
            val = (val << 2) | char2val(s[i]);
        S1.set(val);
    
        int mask = (1 << 20) - 1;
        for (int i=10; i < s.size(); i++) {
            // Calc the hash value for the string ending at position i.
            val = ((val << 2) & mask) | char2val(s[i]);  
            if (S2[val])
                continue;
            if (S1[val]) {
                R.push_back(s.substr(i-10+1, 10));
                S2.set(val);
            }
            else
                S1.set(val);
        }
        return R;
    }

    int char2val(char c) {
        switch (c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
        return -1;
    }
};

int main() {
    return 0;
}