/*******************
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// based on sort
class Solution1 {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())
            return 0;
        
        int n = citations.size();
        sort(citations.begin(), citations.end());
        
        for(int i = 0; i < n; i++) {
            if(citations[i] >= n-i)
                return n-i;   
        }
        return 0;
    }
};

// based on hashtable
class Solution2 {
public: 
    int hIndex(vector<int>& citations) {
        if(citations.empty())
            return 0;
        int n = citations.size();
        vector<int> hash(n + 1, 0);
        for(int i = 0; i < n; ++i){
            if(citations[i] >= n)
                hash[n]++;
            else
                hash[citations[i]]++;
        }
        int paper = 0;
        for(int i = n; i >= 0; --i){
            paper += hash[i];
            if(paper >= i)
                return i;
        }
    }
};

int main() {
    return 0;
}