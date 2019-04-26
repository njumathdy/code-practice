/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        
        vector<int> nums;
        while(head != nullptr) {
            nums.push_back(head->val);
            head = head -> next;
        }
        TreeNode* root = nullptr;
        helper(root, nums, 0, nums.size()-1);
        
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