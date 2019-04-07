/*******************
Given a sorted integer array without duplicates, return the summary of its ranges.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// two pointers
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.empty()) return ans;
        int l = 0, r = 1;
        for(; r < nums.size(); r++) {
            if(nums[r] != nums[r-1]+1) {
                if(r-1 > l)
                    ans.push_back(to_string(nums[l]) + "->" + to_string(nums[r-1]));
                else {
                    ans.push_back(to_string(nums[l]));
                }
                l = r;
            }
        }
        if(l == nums.size()-1)
            ans.push_back(to_string(nums[l]));
        else
            ans.push_back(to_string(nums[l]) + "->" + to_string(nums[nums.size()-1]));
        return ans;               
    }
};

int main() {
    return 0;
}