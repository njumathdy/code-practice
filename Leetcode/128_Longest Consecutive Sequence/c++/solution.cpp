/*******************
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> num_set;
        for(auto num : nums)
            num_set.insert(num);
        
        int longestStreak = 0;
        
        for(auto num : num_set) {
            if(!num_set.count(num-1)) {
                int currentNum = num;
                int currentStreak = 1;
                
                while(num_set.count(currentNum+1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                
                longestStreak = max(currentStreak, longestStreak);
            }
        }
        
        return longestStreak;
    }
};

class Union_Find{
public:
    Union_Find (int N) {
        for (int i = 0; i < N; i++) {
            id.push_back(i);
            sz.push_back(1);
        }
    }

    void Union(int A, int B) {
        int rootA = Find(A);
        int rootB = Find(B);
        if (rootA == rootB) return;
        if (sz[rootA] < sz[rootB]) {
            id[rootA] = rootB;
            sz[rootB] += sz[rootA];
        } else {
            id[rootB] = rootA;
            sz[rootA] += sz[rootB];
        }
    }

    int Find(int p) {
        while (p != id[p]) {
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }

    int maxSize() {
        int res = 0;
        for (auto s : sz)
            res = max(res, s);
        return res;
    }
    
private:
    vector<int> id;
    vector<int> sz;
};

class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        Union_Find uf(nums.size());
        unordered_map<int, int> mapIndex;
        for (int i = 0; i < nums.size(); i++) {
            if (mapIndex.count(nums[i])) continue; // in case of duplicate
            mapIndex.insert(make_pair(nums[i], i));
            
            if (mapIndex.count(nums[i] + 1)) {
                uf.Union(i, mapIndex[nums[i] + 1]);
            }
            if (mapIndex.count(nums[i] - 1)) {
                uf.Union(i, mapIndex[nums[i] - 1]);
            }
        }
        return uf.maxSize();
    }
};

int main() {
    return 0;
}