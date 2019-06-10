/*******************
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    static bool compare(int n1, int n2) {
        return to_string(n1) < to_string(n2);
    }
    
    vector<int> lexicalOrder(int n) {
        if(n == 0)
            return {};
        vector<int> res;
        for(int i = 1; i <= n; i++)
            res.push_back(i);
        
        sort(res.begin(), res.end(), compare);
        
        return res;
    }   
};

class Solution2 {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        helper(1, n, result);
        return result;
    }
    
    void helper(int target, int n, vector<int>& result) {
        if(target > n) {
            return;
        }
        result.push_back(target);
        helper(target * 10, n, result);
        if(target % 10 != 9) {
            helper(target + 1, n, result);
        }
    }
};

int main() {
    return 0;
}