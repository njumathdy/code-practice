/*******************
Return the largest possible k such that there exists a_1, a_2, ..., a_k such that:

Each a_i is a non-empty string;
Their concatenation a_1 + a_2 + ... + a_k is equal to text;
For all 1 <= i <= k,  a_i = a_{k+1 - i}.
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
    int longestDecomposition(string text) {
        int res = 1;
        if(text.size() == 0)
            return 0;
        if(text.size() == 1)
            return 1;
        
        int n = text.size();
        for(int k = 1; k <= n / 2; k++) {
            if(text.substr(0, k) == text.substr(n-k, k))
                res = max(res, 2 + longestDecomposition(text.substr(k, n-2*k)));
        }
        
        return res;
    }
};

int main() {
    return 0;
}