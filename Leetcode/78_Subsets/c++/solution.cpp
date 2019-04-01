/*******************
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>

using namespace std;

// 我的解法：每次选或不选，直接全部遍历一遍。
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        if(nums.size() < 1)
            return ans;
        
        vector<int> temp;
        dfs(ans, nums, temp, 0);
        return ans;
    }
    
    void dfs(vector<vector<int> >& ans, vector<int>& nums, vector<int>& temp, int index) {
        temp.push_back(nums[index]);
        if(index == nums.size() - 1) {
            ans.push_back(temp);
            temp.pop_back();
            ans.push_back(temp);
            return;
        } else {
            dfs(ans, nums, temp, index+1);
            temp.pop_back();
            dfs(ans, nums, temp, index+1);
        }
        
    }
};


// Leetcode代码：每个情况都对应着一个唯一的n位二进制数，转化为对二进制做位运算。
class Solution2 {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > out;
        unsigned bits = 1 << nums.size();
        
        while (bits) {
            vector<int> t;
            for (size_t i = 0; i != nums.size(); ++i) {
                if (bits & (1 << i)) {
                    t.push_back(nums[i]);
                }
            }
            out.push_back(move(t));
            --bits;
        }

        return out;
    }
};

int main() {
    return 0;
}