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

int main() {
    cin >> n;

    int x, y;
    int M = 0;
    vector<int> nums;
    for(int i = 1; i <= n; i++) {
        cin >> x >> y;
        M += x;
        for(int j = 1; j <= x; j++) nums.push_back(y);
    }
    sort(nums.begin(), nums.end());
    int mint = 0;
    for(int i = 0; i <= M / 2; i++) {
        mint = max(mint, nums[i] + nums[M-1-i]);
    }
    cout << mint << endl;

    return 0;
}