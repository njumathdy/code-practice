/*******************
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        inOrder(root, nums);
        return nums[k-1];
    }
    
    void inOrder(TreeNode* root, vector<int>& nums) {
        if(root == nullptr)
            return;
        
        inOrder(root -> left, nums);
        nums.push_back(root -> val);
        inOrder(root -> right, nums);
    }
};

int main() {
    return 0;
}