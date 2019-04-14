/*******************
Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

// 动态规划
// 状态量是以i为结尾的最长满足条件的字符串的长度
class Solution1 {
public:
    int longestValidParentheses(string s) {
        int maxl = 0;
        vector<int> dp(s.size(), 0);
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == ')') {
                if(s[i-1] == '(') {
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                } else if(i - dp[i-1] > 0 && s[i-dp[i-1]-1] == '(') {
                    dp[i] = dp[i-1] + (i - dp[i-1] >= 2 ? dp[i-dp[i-1]-2] : 0) + 2;
                }
                maxl = max(maxl, dp[i]);
            }
        }
        return maxl;
    }
};

// 利用栈
class Solution2 {
public:
    int longestValidParentheses(string s) {
        int maxl = 0;
        stack<int> stac;
        stac.push(-1);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                stac.push(i);
            } else {
                stac.pop();
                if(stac.empty()) {
                    stac.push(i);
                } else {
                    maxl = max(maxl, i - stac.top());
                }
            }
        }
        return maxl;
    }
};

// 空间最优: O(1)
class Solution3 {
public:
    int longestValidParentheses(string s) {
        int maxl = 0;
        int left = 0, right = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                left++;
            else {
                right++;
            }
            if(left == right) {
                maxl = max(maxl, 2*right);
            } else if(right > left) {
                left = 0;
                right = 0;
            }
        }
        
        left = 0;
        right = 0;
        for(int i = s.size()-1; i >= 0; i--) {
            if(s[i] == '(')
                left++;
            else
                right++;
            if(left == right)
                maxl = max(maxl, 2*left);
            else if(left > right) {
                left = 0;
                right = 0;
            }
        }
        
        return maxl;
    }
};

int main() {
    return 0;
}