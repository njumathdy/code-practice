/*******************
度度熊有一个N个数的数组，他想将数组从小到大 排好序，但是萌萌的度度熊只会下面这个操作： 
任取数组中的一个数然后将它放置在数组的最后一个位置。 
问最少操作多少次可以使得数组从小到大有序？
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int n;
vector<int> nums;

void solve(vector<int>& nums) {
    map<int, int> map;
    for(int i = 0; i < n; i++) {
        map[nums[i]] = i;
    }
    sort(nums.begin(), nums.end());
    int t = n, count = 0;
    for(int i = 0; i < n-1; i++) {
        if(map[nums[i]] > map[nums[i+1]]) {
            map[nums[i+1]] = t++;
            count++;
        }
    }
    cout << count << endl;
}

int main() {
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }
    solve(nums);

    return 0;
}