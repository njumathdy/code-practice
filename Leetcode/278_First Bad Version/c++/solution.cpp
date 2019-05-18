/*******************
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        int mid = 0;
        
        while(l < r) {
            mid = l + (r - l) / 2;
            if(isBadVersion(mid)) {
                if(!isBadVersion(mid-1))
                    return mid;
                else 
                    r = mid;
            } else 
                l = mid + 1;
        }
        return l;
    }
};

int main() {
    return 0;
}