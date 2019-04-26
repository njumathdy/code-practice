/*******************
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// my solution，提交的时间和空间数据都较差
class Solution1 {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;
        if(nums.size() == 1)
            return new TreeNode(nums[0]);
        
        return help(nums, 0, nums.size());
    }
    
    TreeNode* help(vector<int> nums, int i, int j) {
        if(i == j)
            return nullptr;
        if(j == i + 1)
            return new TreeNode(nums[i]);
        
        int k = (i + j) / 2;
        TreeNode* node = new TreeNode(nums[k]);
        node -> left = help(nums, i, k);
        node -> right = help(nums, k+1, j);
        return node;
    }
};

// 将指针也作为参数传递，可以减少所需要的空间
class Solution2 {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;
        helper(root, nums, 0, nums.size() - 1);
        return root;
    }
    
    void helper(TreeNode*& root, vector<int>& nums, int s, int e) {
        if(s > e) return;
        if(s == e) {
            root = new TreeNode(nums[s]);
            return;
        }
        int mid = (s + e) / 2;
        root = new TreeNode(nums[mid]);
        helper(root->left, nums, s, mid - 1);
        helper(root->right, nums, mid + 1, e);
    }
};

int main() {
    return 0;
}