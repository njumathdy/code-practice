/*******************
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<int> nums, res;
        inorder(root, nums);
        
        map<int, int> count;
        for(int i = 0; i < nums.size(); i++) {
            if(count.find(nums[i]) != count.end())
                count[nums[i]]++;
            else
                count[nums[i]] = 1;
        }
        int maxnum = 0;
        for(auto c = count.begin(); c != count.end(); c++)
            maxnum = max(maxnum, c -> second);
        for(auto c = count.begin(); c != count.end(); c++) {
            if(c -> second == maxnum)
                res.push_back(c -> first);
        }
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