/*******************
You are given a string containing only 4 kinds of characters 'Q', 'W', 'E' and 'R'.
A string is said to be balanced if each of its characters appears n/4 times where n is the length of the string.
Return the minimum length of the substring that can be replaced with any other string of the same length to make the original string s balanced.
Return 0 if the string is already balanced.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool check(const vector<int> &tot, const vector<int> &sum, int target) {
        for (int i = 0; i < 4; i++)
            if (sum[i] - tot[i] > target)
                return false;

        return true;
    }

    int balancedString(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        mp['Q'] = 0; mp['W'] = 1; mp['E'] = 2; mp['R'] = 3;

        vector<int> sum(4, 0);
        for (int i = 0; i < n; i++)
            sum[mp[s[i]]]++;

        if (sum[0] == sum[1] && sum[0] == sum[2] && sum[0] == sum[3])
            return 0;

        int ans = n;
        vector<int> tot(4);
        for (int i = 0, j = 0; i < n; i++) {
            tot[mp[s[i]]]++;

            while (j <= i && check(tot, sum, n / 4)) {
                ans = min(ans, i - j + 1);
                tot[mp[s[j]]]--;
                j++;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}