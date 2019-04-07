/*******************
一个数组，数组和为0，每个位置表示该位置有多少水果，大于0表示剩余，小于0表示需求。
将一个水果移动k个位置需要k个单位花费，求最小花费是的每个位置均为0。
0%
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

const int maxn = 300001;

int n;
vector<int> demand(maxn, 0);
int ans = 0;

// 
void solve(vector<int>& nums) {
    for(int i = 0; i < n-1; i++) {
        ans += abs(nums[i]);
        nums[i+1] += nums[i];
    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        demand[i] = temp;
    }
    solve(demand);

    return 0;
}