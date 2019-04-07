/*******************
一个数组，每次只能从两边选一个数，将选到的数从左到右放置，最后得到一个排列。
对相邻的两个数的差的绝对值求和，求最大的和是多少。
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 101;

int n;
vector<int> nums(101, 0);
int maxS = 0;

// 测试用例只过了10%
void solve(vector<int>& num, bool head) {
    vector<int> temp;
    int l = 0, r = n-1;
    if(l == r)
        return;
    if(head) {
        temp.push_back(num[l]);
        l++;
    } else {
        temp.push_back(num[r]);
        r--;
    }
    while(r > l) {
        if(abs(num[l] - temp[temp.size()-1]) > abs(num[r]-temp[temp.size()-1])) {
            temp.push_back(num[l]);
            l++;
        }    
        else {
            temp.push_back(num[r]);
            r--;
        }    
    }
    int sum = 0;
    for(int i = 0; i < temp.size()-1; i++)
        sum += abs(temp[i+1]-temp[i]); 
    maxS = max(maxS, sum);  
}

int main() {
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        nums[i] = temp;
    }
    solve(nums, true);
    solve(nums, false);
    cout << maxS << endl;
    return 0;
}