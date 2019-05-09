/*******************
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

// dfs
class Solution1 {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> result;
        int left_removed = 0;
        int right_removed = 0;
        for(auto c : s) {
            if(c == '(') {
                ++left_removed;
            }
            if(c == ')') {
                if(left_removed != 0) {
                    --left_removed;
                }
                else {
                    ++right_removed;
                }
            }
        }
        helper(s, 0, left_removed, right_removed, 0, "", result);
        return vector<string>(result.begin(), result.end());
    }
private:
    // pair是记录未配对的左括号的数量
    void helper(string s, int index, int left_removed, int right_removed, int pair, string path, unordered_set<string>& result) {
        if(pair < 0)
            return;
        if(index == s.size()) {
            if(left_removed == 0 && right_removed == 0 && pair == 0) {
                result.insert(path);
            }
            return;
        }
        if(s[index] != '(' && s[index] != ')') {
            helper(s, index + 1, left_removed, right_removed, pair, path + s[index], result);
        }
        else {
            if(s[index] == '(') {
                if(left_removed > 0) {
                    helper(s, index + 1, left_removed - 1, right_removed, pair, path, result);
                }
                helper(s, index + 1, left_removed, right_removed, pair + 1, path + s[index], result);
            }
            if(s[index] == ')') {
                if(right_removed > 0) {
                    helper(s, index + 1, left_removed, right_removed - 1, pair, path, result);
                }
                if(pair > 0) {
                    helper(s, index + 1, left_removed, right_removed, pair - 1, path + s[index], result);
                }
            }
        }
    }
};

class Solution2 {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0;
        int r = 0;
        for(char c: s)
            if(c == '(')
                ++l;
            else if(c == ')')
            {
                if(l == 0)
                    ++r;
                else
                    --l;
            }
        vector<string> ret;
        dfs(ret, s, l, r, 0);
        return ret;
    }

    bool isValid(string s) {
        int cnt = 0;
        for(char c: s)
        {
            if(c == '(')
                ++cnt;
            else if(c == ')')
                --cnt;
            if(cnt < 0)
                return false;
        }
        return cnt == 0;
    }

    void dfs(vector<string>& ret, string s, int l, int r, int pos) {
        if(l == 0 && r == 0 && isValid(s))
        {
            ret.push_back(s);
            return;
        }
        for(int i = pos; i < s.size(); i++)
        {
            string str = s;
            if(str[i] == '(' && l > 0)
            {
                if(i == pos || str[i] != str[i-1])
                {
                    str.erase(i, 1);
                    dfs(ret, str, l - 1, r, i);
                }
            }
            if(str[i] == ')' && r > 0)
            {
                if(i == pos || str[i] != str[i-1])
                {
                    str.erase(i, 1);
                    dfs(ret, str, l, r - 1, i);
                }
            }
        }
    }
};

int main() {
    return 0;
}