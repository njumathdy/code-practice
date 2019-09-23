#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int n, k;

int main() {
    cin >> n >> k;
    vector<int> nums(n+1);
    nums[0] = 0;
    for(int i = 1; i <= n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());
    vector<int> res;
    res.push_back(nums[1]);
    int i = 1;
    while(i <= n) {
        int j = 1;
        while(i+j <= n && nums[i+j] == nums[i]) {
            j++;
        }
        if(i + j > n) break;
        else res.push_back(nums[i+j] - nums[i]);
        i = i+j;
    }
    for(int i = 1; i <= k; i++) {
        if(i > res.size()) {
            cout << 0 << endl;
        } else 
            cout << res[i-1] << endl;
    }

    return 0;
}