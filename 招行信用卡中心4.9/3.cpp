/*******************
cmr and chemistry
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

int n;
vector<int> nums;
int ans = INT_MAX;

int minOp(int a, int b) {
    if(a == b)
        return 1;
    int ans;
    if(a > b) {
        int temp = 0;
        while(a > b) {
            a /= 2;
            temp++;
        }
        if(a == b)
            ans = temp;
        else
            ans = -1;   
    } else {
        int temp = 0;
        while(a < b) {
            a *= 2;
            temp++;
        }
        if(a == b)
            ans = temp;
        else 
            ans = -1;
    }
    return ans;
}

void solve(vector<int>& nums) {
    for(int i = 1; i < nums[nums.size()-1]; i++) {
        int sum = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(minOp(nums[j], i) == -1) {
                sum = -1;
                break;
            }
            else 
                sum += minOp(nums[j], i);
        }
        if(sum == -1)
            continue;
        else 
            ans = min(ans, sum);
    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());
    solve(nums);

    return 0;
}