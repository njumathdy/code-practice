/*******************
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
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
    vector<int> countBits(int num) {
        if(num == 0)
            return {0};
        
        vector<int> dp(num + 1, 0);
        for(int i = 1; i <= num; i++) {
            if(i % 2)
                dp[i] = dp[i-1] + 1;
            else {
                int temp = 0, j = i - 1;
                while(j & 1) {
                    temp++;
                    j >>= 1;
                }
                dp[i] = dp[i-1] + 1 - temp;
            }
        }
        return dp;
    }
};

int main() {
    return 0;
}