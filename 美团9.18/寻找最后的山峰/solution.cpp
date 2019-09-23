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

vector<int> nums;

void solve() {
    int n = nums.size(), i;
    if(nums.size() == 1) {
        cout << 0 << endl;
    }
    if(nums[n-1] > nums[n-2]) {
        cout << n-1 << endl;
        return;
    }
    for(i = n-2; i > 0; i--) {
        if(nums[i] > nums[i+1] && nums[i] > nums[i-1]) {
            cout << i << endl;
            return;
        }
    }
    if(i == 0) {
        cout << 0 << endl;
        return;
    }
}

int main() {
    int n;
    while(cin >> n) {
        nums.push_back(n);
    }
    solve();

    return 0;
}