/*******************
You are given an integer array nums and you have to return a new counts array. 
The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <numeric>
#include <unordered_map>

using namespace std;

// O(n^2) time complexity, TLE
class Solution1 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.empty())
            return {};
        
        vector<int> res(nums.size(), 0);
        int n = nums.size();
        int i, j;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(nums[j] < nums[i])
                    res[i]++;
            }
        }
        
        return res;
    }
};

// based on mergesort to count reverse pairs
class Solution2 {
protected:
    void merge_countSmaller(vector<int>& indices, int first, int last, 
                            vector<int>& results, vector<int>& nums) {
        int count = last - first;
        if (count > 1) {
            int step = count / 2;
            int mid = first + step;
            merge_countSmaller(indices, first, mid, results, nums);
            merge_countSmaller(indices, mid, last, results, nums);
            vector<int> tmp;
            tmp.reserve(count);
            int idx1 = first;
            int idx2 = mid;
            int semicount = 0;
            while ((idx1 < mid) || (idx2 < last)) {
                if ((idx2 == last) || ((idx1 < mid) &&
                       (nums[indices[idx1]] <= nums[indices[idx2]]))) {
					tmp.push_back(indices[idx1]);
                    results[indices[idx1]] += semicount;
                    ++idx1;
                } else {
					tmp.push_back(indices[idx2]);
                    ++semicount;
                    ++idx2;
                }
            }
            move(tmp.begin(), tmp.end(), indices.begin()+first);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n, 0);
        vector<int> indices(n, 0); // 记录每个数字的下标
        iota(indices.begin(), indices.end(), 0);
        merge_countSmaller(indices, 0, n, results, nums);
        return results;
    }
};

class BIT {
public:
    BIT(int n) {
        nums.resize(n+1);
        fill(nums.begin(), nums.end(), 0);
    }
    ~BIT() { nums.clear(); }

    void update(int i, int val) {
        while (i < nums.size()) {
            nums[i] += val;
            i += i & -i;
        }
    }

    int sum(int i) {
        int ret = 0;
        while (i > 0) {
            ret += nums[i];
            i -= i & -i;
        }
        return ret;
    }
private:
    vector<int> nums;
};

// based on binary indexed tree
class Solution3 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.empty())
            return {};
        if(nums.size() == 1)
            return {0};
        
        int n = nums.size();
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        unordered_map<int, int> htable;
        for (int i = 0; i < n; i++) {
            htable[temp[i]] = i;
        }

        BIT tree(n);
        vector<int> res(n);
        for (int i = n-1; i >= 0; i--) {
            res[i] = tree.sum(htable[nums[i]]);
            tree.update(htable[nums[i]]+1, 1);
        }
        return res;
    }   
};

int main() {
    return 0;
}