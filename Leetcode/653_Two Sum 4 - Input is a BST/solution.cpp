/*******************
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr)
            return false;
        
        vector<int> nums;
        inorder(root, nums);
        
        int n = nums.size();
        int l = 0, r = n-1;
        while(l < r) {
            int sum = nums[l] + nums[r];
            if(sum == k)
                return true;
            if(sum < k)
                l++;
            else
                r--;
        }
        return false;
    }
    
    void inorder(TreeNode* root, vector<int>& nums) {
        if(root == nullptr)
            return;
        inorder(root -> left, nums);
        nums.push_back(root -> val);
        inorder(root -> right, nums);
    }
};

class Solution2 {
public:
    bool findTarget(TreeNode* root, int k) {
        set<int> s;
        return find(root, k, s);
    }
    
    bool find(TreeNode* root, int k, set<int>& s) {
        if(root == nullptr)
            return false;
        
        if(s.find(k - root -> val) != s.end())
            return true;
        
        s.insert(root -> val);
        
        return find(root -> left, k, s) || find(root -> right, k, s);
    }
};

int main() {
    return 0;
}