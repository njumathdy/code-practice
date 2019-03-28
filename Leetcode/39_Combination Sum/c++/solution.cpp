/*******************
*Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>

using namespace std;

// 回宿法的思想
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        if(candidates.size() == 0)
            return ans;
        
        vector<int> temp;
        
        combinationSum(candidates, target, ans, temp, 0);
        
        return ans;   
    }
    
    void combinationSum(vector<int>& candidates, int target, vector<vector<int> >& ans, vector<int>& temp, int start) {
        for(int i = start; i < candidates.size(); ++i){
            temp.push_back(candidates[i]);
            target = target- candidates[i];
            if(target == 0){//条件满足
                ans.push_back(temp);
            }
            if(target < 0){
                target += candidates[i];
                temp.pop_back();
                continue;
            }
            combinationSum(candidates, target, ans, temp, i);//递归调用
            // 回溯
            temp.pop_back();
            target += candidates[i];
        }
    }
};

int main() {
    return 0;
}
