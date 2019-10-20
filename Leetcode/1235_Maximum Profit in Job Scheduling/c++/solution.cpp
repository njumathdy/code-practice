/*******************
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
You're given the startTime , endTime and profit arrays, you need to output the maximum profit you can take such that there are no 2 jobs in the subset with overlapping time range.
If you choose a job that ends at time X you will be able to start another job that starts at time X.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int> > jobs(n);
        for(int i = 0; i < n; i++) {
            jobs[i].push_back(startTime[i]);
            jobs[i].push_back(endTime[i]);
            jobs[i].push_back(profit[i]);
        }
        auto comp = [](vector<int>& j1, vector<int>& j2) { return j1[1] < j2[1]; };
        sort(jobs.begin(), jobs.end(), comp);
        vector<int> dp(n);
        dp[0] = jobs[0][2];
        for(int i = 1; i < n; i++) {
            int l = 0, r = i-1;
            while(l < r) {
                int mid = l + (r - l) / 2;
                if(jobs[mid+1][1] <= jobs[i][0])
                    l = mid+1;
                else
                    r = mid;
            }
            if(jobs[l][1] <= jobs[i][0])
                dp[i] = max(dp[i-1], dp[l] + jobs[i][2]);
            else
                dp[i] = max(dp[i-1], jobs[i][2]);
        }
        return dp[n-1];
    }
};

int main() {
    return 0;
}