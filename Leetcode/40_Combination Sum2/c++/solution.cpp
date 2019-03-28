/*******************
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>

using namespace std;

// DFS, 用used数组来标记每个数是否被使用过
class Solution {
public:
    void DFS(int now, int p, int target, vector<int>& temp, vector<int>& cans, int* used, vector<vector<int> >& result){
        if(now == target){
            result.push_back(temp);
            return;
        }
        for(int i = p + 1; i < cans.size(); i++){
            if(now + cans[i] > target) return;
            // 前一个没有被选择说明这个也不会被选择，减少搜索量
            if(i && cans[i] == cans[i-1] && !used[i-1]) continue;
            used[i] = 1; 
            temp.push_back(cans[i]);
            DFS(now+cans[i], i, target, temp, cans, used, result);
            // 回溯
            used[i] = 0; 
            temp.pop_back();
        }
    }

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int> > result;
        if(target == 0) return result;
        sort(candidates.begin(), candidates.end());
        int used[candidates.size()] = {0};
        DFS(0, -1, target, temp, candidates, used, result);
        return result;
    }   
};

int main() {
    return 0;
}