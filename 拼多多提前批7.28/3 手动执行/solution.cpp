/*******************
拓扑排序
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int N, M;
vector<int> P(10010, 0);
vector<vector<int> > Dep(50010, vector<int>(2, 0));

void solve(vector<int>& P, vector<vector<int> >& dep) {

}

int main() {
    string s;
    getline(cin, s);
    vector<int> nums;
    istringstream iss(s);
    int num;
    while(iss >> num)
        nums.push_back(num);
    for(auto num : nums)
        cout << num << " ";
    
    return 0;
}