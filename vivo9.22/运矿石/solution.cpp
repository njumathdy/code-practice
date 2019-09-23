#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int T;

void solve(vector<int>& nums) {
    int sum = 0, n = nums.size();
    for(int i = 0; i < n; i++) 
        sum += nums[i];

    int l = n / 2;
    int sum1 = sum / 2;

    vector<vector<bool> > dp(n+1, vector<bool>(sum1+1, false));
    for(int i = 0; i <= n; i++) dp[i][0] = true;
    for(int i = 1; i <= sum1; i++) dp[0][i] = false;

    for(int i = 1; i <= n; i++) {
        for(int j = min(l, i); j >= 1; j--) {
            for(int s = 1; s <= sum1; s++) {
                if(s >= nums[i-1] && dp[j-1][s-nums[i-1]]) {
                    dp[j][s] = true;
                }
            }
        }
    }

    for(int s = sum1; s >= 0; s--) {
        if(dp[l][s]) {
            cout << s << ' ' << sum - s << endl;
            return;
        }
    }
}

int main() {
    cin >> T;
    int n;
    for(int i = 1; i <= T; i++) {
        cin >> n;
        vector<int> nums;
        for(int j = 0; j < n; j++) {
            int t;
            cin >> t;
            nums.push_back(t);
        }
        solve(nums);
    }

    return 0;
}