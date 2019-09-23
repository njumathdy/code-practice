/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <limits.h>

using namespace std;

void solve(vector<int>& nums) {
    if(nums.empty()) {
        cout << -1 << endl;
        return;
    }
    if(nums.size() == 1) {
        cout << 0 << endl;
        return;
    }

    int n = nums.size();

    vector<int> dp(n, -1);
    dp[n-1] = 0;
    for(int i = n-2; i >= 0; i--) {
        if(nums[i] == 0) continue;
        int pos = i + nums[i];
        for(int j = i+1; j <= min(pos, n-1); j++) {
            if(dp[j] == -1) continue;
            if(dp[i] > 0) dp[i] = min(dp[i], 1+dp[j]);
            else dp[i] = 1 + dp[j];
        }
        // cout << dp[i] << endl;
    }

    cout << dp[0] << endl;

    return;
}

int main() {
    vector<int> nums;
    int t;
    while(cin >> t) nums.push_back(t);
    solve(nums);

    return 0;
}