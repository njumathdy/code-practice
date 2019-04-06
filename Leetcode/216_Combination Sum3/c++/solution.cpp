/*******************
Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>

using namespace std;

// 回溯法
class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        vector<int> temp;
        dfs(ans, temp, k, n);
        return ans;    
    }
    
    void dfs(vector<vector<int>>& ans, vector<int>& temp, int k, int n) {
        if(temp.size() == k && n == 0)
            ans.push_back(temp);
        for(int i = temp.empty()?1:temp.back()+1; i <= 9; i++) {
            if(n - i < 0)
                break;
            temp.push_back(i);
            dfs(ans, temp, k, n-i);
            temp.pop_back();
        }
    }    
};

int main() {
    return 0;
}