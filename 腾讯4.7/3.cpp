/*******************
80%
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

const int maxn = 100001;

int n, k;
vector<int> nums;
int indexOfMin = 0;

void minNotZero(vector<int>& nums) {
    for(int i = indexOfMin; i < n; i++) {
        if(nums[i] == 0)
            indexOfMin++;
        else
            break;    
    }
}

void solve(vector<int>& nums) {
    int i = 1;
    while(i <= k) {
        minNotZero(nums);
        cout << nums[indexOfMin] << endl;
        int t = nums[indexOfMin];
        for(int j = indexOfMin; j < n; j++) {
            nums[j] -= t;
        }
        i++;
    }
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());
    solve(nums);
    return 0;
}