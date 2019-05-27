/*******************
Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

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

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) 
            return 0;
        
        int n = citations.size();
        for(int i = 0; i < n; i++) {
            if(citations[i] >= n-i)
                return n - i;
        }
        return 0;
    }
};

int main() {
    return 0;
}