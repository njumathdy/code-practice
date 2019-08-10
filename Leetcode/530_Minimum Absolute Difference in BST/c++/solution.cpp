/*******************
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
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

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        
        int res = INT_MAX;
        for(int i = 0; i < nums.size()-1; i++)
            res = min(res, nums[i+1]-nums[i]);
        
        return res;        
    }
    
    void inorder(TreeNode* node, vector<int>& nums) {
        if(node == nullptr)
            return;
        
        inorder(node -> left, nums);
        nums.push_back(node -> val);
        inorder(node -> right, nums);
    }
};

int main() {
    return 0;
}