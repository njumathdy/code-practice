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

int n;

void solve(vector<int>& nums) {
    vector<int> count(n, 0);

    int maxn = 0, pos;
    for(int i = n-1; i > 0; i--) {
        int j = i-1;
        while(j >= 0 && nums[j] < nums[i]) {
            j--;
        }
        if(j >= 0) {
            count[j]++;
            maxn = max(maxn, count[j]);
        }        
    }

    if(maxn == 0) {
        cout << 0 << endl;
        return;
    }

    for(int i = 0; i< n; i++) {
        if(count[i] == maxn) {
            cout << nums[i] << endl;
            return;
        }
    }
}

int main() {
    cin >> n;

    vector<int> height(n);
    for(int i = 0; i < n; i++)
        cin >> height[i];

    solve(height);

    return 0;
}