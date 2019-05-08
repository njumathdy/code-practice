/*******************
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// dfs
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int temp = 0, sum = 0;
        dfs(root, temp, sum);
        return sum;
    }
    
    void dfs(TreeNode* node, int& temp, int& sum) {
        if(node == nullptr)
            return;
        if(node -> left == nullptr && node -> right == nullptr) {
            temp = temp * 10 + node -> val;
            sum += temp;
            return;
        }
        temp = temp * 10 + node -> val;
        int t = temp;
        dfs(node -> left, temp, sum);
        temp = t;
        dfs(node -> right, temp, sum);
    }
};

int main() {
    return 0;
}