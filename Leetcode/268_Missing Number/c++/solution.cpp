/*******************
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, 
find the one that is missing from the array.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1) / 2, actualSum = 0;
        for(int i = 0; i < n; i++)
            actualSum += nums[i];
        
        return sum - actualSum;       
    }
};

// 利用异或
class Solution2 {
public: 
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            ans ^= (i ^ nums[i]);
        }
        return ans;
    }
};

int main() {
    return 0;
}