/*******************
读入一个数列和N值，返回按优先级排序的N个数，满足：
1. 所有偶数优先级大于奇数
2. 同为偶数或同为奇数时，数值大的优先级高
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

bool comp(int a, int b) {
    if(a % 2 == 0 && b % 2 == 1)
        return 1;
    if(a % 2 == 1 && b % 2 == 0)
        return 0;

    return a > b;
}

int main() {
    string s;
    cin >> s;

    vector<int> nums;
    int temp = 0, N = 0;
    bool flag = false;
    for(int i = 0; i < s.size(); i++) {
        if(flag) {
            N = N * 10 + s[i] - '0';
        } else {
            if(s[i] != ',' && s[i] != ';') {
                temp = temp * 10 + s[i] - '0';
            } else if (s[i] == ',') {
                nums.push_back(temp);
                temp = 0;
            } else {
                nums.push_back(temp);
                flag = true;
            }
        }   
    }
    sort(nums.begin(), nums.end(), comp);

    for(int i = 0; i < N; i++) {
        if(i < N-1) 
            cout << nums[i] << ',';
        else
            cout << nums[i] << endl;
    }

    return 0;
}