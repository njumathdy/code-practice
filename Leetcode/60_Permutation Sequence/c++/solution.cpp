/*******************
The set [1,2,3,...,n] contains a total of n! unique permutations.
Given n and k, return the kth permutation sequence.
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
    string getPermutation(int n, int k) {
        string s(n, '0');
        int i, j, f = 1;
        for(i = 1; i <= n; i++) {
            f *= i;
            s[i-1] += i;
        }
        for(i = 0, k--; i < n; i++) {
            f /= n-i;
            j = i + k / f; // calculate index of char to put at s[i]
            char c=s[j];
            // 保证右边仍是递增的
            for(;j>i;j--)
                s[j]=s[j-1];
            k %= f;
            s[i]=c;
        }
        return s;
    }
};

int main() {
    return 0;
}