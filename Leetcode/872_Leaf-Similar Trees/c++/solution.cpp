/*******************
Consider all the leaves of a binary tree.  
From left to right order, the values of those leaves form a leaf value sequence.
Two binary trees are considered leaf-similar if their leaf value sequence is the same.
Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1, nums2;
        getLeaf(root1, nums1);
        getLeaf(root2, nums2);
        
        if(nums1.size() != nums2.size())
            return false;
        for(int i = 0; i < nums1.size(); i++) {
            if(nums1[i] != nums2[i])
                return false;
        }
        return true;
    }
    
    void getLeaf(TreeNode* root, vector<int>& nums) {
        if(root == nullptr)
            return;
        if(root -> left == nullptr && root -> right == nullptr) {
            nums.push_back(root -> val);
            return;
        }
        getLeaf(root -> left, nums);
        getLeaf(root -> right, nums);
    }
};

int main() {
    return 0;
}