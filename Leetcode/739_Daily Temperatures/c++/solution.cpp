/*******************
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <limits.h>
#include <stack>

using namespace std;

// 从后向前处理
class Solution1 {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        if(n == 0)
            return {};
        
        vector<int> ans(n, 0);
        // 用来记录每个数出现的位置
        vector<int> next(101, INT_MAX);
        
        for(int i = n - 1; i >= 0; --i) {
            int temp_index = INT_MAX;
            for(int j = T[i] + 1; j <= 100; j++) {
                if(next[j] < temp_index)
                    temp_index = next[j];
            }
            if(temp_index < INT_MAX)
                ans[i] = temp_index - i;
            next[T[i]] = i;
        }
        
        return ans;
    }
};

// using stack
class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        if(n == 0)
            return {};
        
        vector<int> ans(n, 0);
        stack<int> s;
        
        // 维护一个从栈顶到栈底的递增的序列
        for(int i = n - 1; i >= 0; i--) {
            
            while(!s.empty() && T[i] >= T[s.top()])
                s.pop();
            ans[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }
        
        return ans;
    }
};

int main() {
    return 0;
}