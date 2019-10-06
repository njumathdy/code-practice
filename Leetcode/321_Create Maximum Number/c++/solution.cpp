/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// Solution1
class Solution {
public:
    vector<int> maxVector(vector<int> nums, int k) {
        while (nums.size() > k) {
            int i = 0, n = nums.size();
            for (; i < n - 1; ++i) {
                if (nums[i] < nums[i + 1]) {
                    nums.erase(nums.begin() + i);
                    break;
                }
            }
            if (i == n - 1) nums.erase(nums.begin() + i);
        }

    return nums;
}

    bool compare(vector<int> &nums1, int i, vector<int> &nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            ++i;
            ++j;
        }
        if (j == nums2.size()) return true;
        if (i < nums1.size() && nums1[i] > nums2[j]) return true;
        return false;
    }

    vector<int> merge(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> res(k, 0);
        for (int i = 0, j = 0, r = 0; r < k; ++r) {
            res[r] = compare(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
        }

        return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> res(k, 0);

        for (int i = max(0, k - n); i <= min(k, m); ++i) {
            auto v1 = maxVector(nums1, i);
            auto v2 = maxVector(nums2, k - i);
            auto tmp = merge(v1, v2, k);
            if (compare(tmp, 0, res, 0)) res = tmp;
        }

        return res;
    }
};

class Solution2 {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, INT_MIN);
        int m = nums1.size(), n = nums2.size();
        int m_min = max(0, k - n), m_max = min(m, k);
        vector<int> curr(k, 0), v1(k, 0), v2(k, 0);
        for(int i = m_min; i <= m_max; ++i){
            getmax(nums1, v1, i);
            getmax(nums2, v2, k - i); 
            merge(curr, v1, v2);
            
            if(curr > res)
                res = curr;
        }
        return res;
    }
private:
    bool greater(const vector<int>& lhs, vector<int>::size_type i, const vector<int>& rhs, vector<int>::size_type j){
        while(i < lhs.size() && j < rhs.size() && lhs[i] == rhs[j]){
            ++i;
            ++j;
        }
        return j == rhs.size() || (i < lhs.size() && lhs[i] > rhs[j]);
    }
    void merge(vector<int>& res, const vector<int>& lhs, const vector<int>& rhs){
        int n = res.size();
        for(int k = 0, i = 0, j = 0; k < n; ++k){
            res[k] = greater(lhs, i, rhs, j)?lhs[i++]:rhs[j++];
        }
        return;
    }
    void getmax(vector<int>& nums, vector<int>& res, int k){
        res.resize(k);
        int n = nums.size();
        for(int i = 0, j = 0; i < n; ++i){
            while(j + n - i > k && j > 0 && nums[i] > res[j-1]) // j + n - i > k 意味着剩下的数的数量仍很多
                --j;
            if(j < k)
                res[j++] = nums[i];
        }
        return;
    }
};

int main() {
    return 0;
}