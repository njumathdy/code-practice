/*******************
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// 摩尔投票。
// 因为最多只能有两个，先统计数组中出现系数最多的两个数。然后再统计这两个数出现的次数是否超过1/3.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, a=0, b=1;
    
        for(auto n: nums){
            if (a==n){
                cnt1++;
            }
            else if (b==n){
                cnt2++;
            }
            else if (cnt1==0){
                a = n;
                cnt1 = 1;
            }
            else if (cnt2 == 0){
                b = n;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
    
        cnt1 = cnt2 = 0;
        for(auto n: nums){
            if (n==a)   cnt1++;
            else if (n==b)  cnt2++;
        }
    
        vector<int> res;
        if (cnt1 > nums.size()/3)   res.push_back(a);
        if (cnt2 > nums.size()/3)   res.push_back(b);
        return res;
    }
};

int main() {
    return 0;
}