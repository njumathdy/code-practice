/*******************
答案是从后向前找一个最长的递增序列，用数组长度减去该递增序列长度即可。
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int n;
vector<int> nums;

void solve(vector<int>& num) {
    int l = num.size(), i;
    for(i = l-1; i >= 1; i--) {
        if(num[i] > num[i-1]) 
            continue;
        else 
            break;
    }
    cout << n - (l-1-i) << endl;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        nums.push_back(t);
    }
    solve(nums);

    return 0;
}