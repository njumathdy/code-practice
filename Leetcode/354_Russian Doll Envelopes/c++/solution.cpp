/*******************
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
What is the maximum number of envelopes can you Russian doll? (put one inside other)
*******************/
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
    int maxEnvelopes(vector<vector<int> >& envelopes) {
        if (envelopes.empty()) return 0;
        
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(envelopes.size(), 1);
        for (int i = 0; i < envelopes.size(); ++i)
            for (int j = 0; j < i; ++j)
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
                    dp[i]  = max(dp[i] , dp[j] + 1);
        return *max_element(dp.begin(), dp.end());
    }
};

class Solution2 {
public:
    int maxEnvelopes(vector<vector<int> >& envelopes) {
        if(envelopes.size() < 2)
            return envelopes.size();
        
        auto comp = [](vector<int>& a, vector<int>& b) {
            return a[0] == b[0] ? (a[1] > b[1]) : (a[0] < b[0]);
        };
        
        sort(envelopes.begin(), envelopes.end(), comp);
        
        vector<int> nums;
        for(int i = 0; i < envelopes.size(); i++) {
            nums.push_back(envelopes[i][1]);
        }
        
        return lengthOfLIS(nums);
    }
    
    void insertWithBS(vector<int>& tail, int num) {
        if (tail.empty()) {
            tail.push_back(num);
            return;
        }
        
        if (tail[0] >= num) {
            tail[0] = num;
            return;
        }
        
        if (tail[tail.size() - 1] < num) {
            tail.push_back(num);
            return;
        }
        
        int start = 0, end = tail.size() - 1;
        while(start <= end) {
            int mid = (start + end) / 2;
            if (num == tail[mid]) {
                return;
            } else if (num > tail[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        tail[start] = num;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tail;
        for (auto num : nums) {
            insertWithBS(tail, num);
        }
        return tail.size();
    }
};

int main() {
    return 0;
}