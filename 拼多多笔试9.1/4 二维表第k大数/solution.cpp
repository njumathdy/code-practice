/*******************
Nearly every one have used the Multiplication Table. But could you find out the k-th smallest number quickly from the multiplication table?
Given the height m and the length n of a m * n Multiplication Table, and a positive integer k, you need to return the k-th smallest number in this table.
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
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m * n;
        while(lo < hi) {
            int mi = lo + (hi -lo) / 2;
            if(!enough(mi, m, n, k))
                lo = mi + 1;
            else
                hi = mi;
        }
        
        return lo;
    }
    
    bool enough(int x, int m, int n, int k) {
        int count = 0;
        for(int i = 1; i <= m; i++) {
            count += min(x / i, n);
        }
        
        return count >= k;
    }
};

int main() {
    return 0;
}

          
   