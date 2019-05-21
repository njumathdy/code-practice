/*******************
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
	    int k = primes.size();
        // 记录每个素数出现的次数
	    vector<int> pos(k, 0);
	    vector<int> res(n);
	    res[0] = 1;
	    for (int i = 1; i < n; i++) {
		    int temp = INT_MAX;
		    for (int j = 0; j < k; j++) 
			    temp = min(temp, res[pos[j]] * primes[j]);
		    for (int j = 0; j < k; j++) {
			    if (temp == res[pos[j]] * primes[j])
				    pos[j]++;
		    }
		    res[i] = temp;
	    }

	    return res[n - 1];
    }
};

int main() {
    return 0;
}