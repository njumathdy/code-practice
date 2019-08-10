/*******************
Given the root of a tree, you are asked to find the most frequent subtree sum. 
The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). 
So what is the most frequent subtree sum value? 
If there is a tie, return all the values with the highest frequency in any order.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        vector<int> res;
        unordered_map<int, int> records;
        queue<TreeNode*> q;
        q.push(root);
        int maxsum = 0;
        while(!q.empty()) {
            int sum = 0;
            TreeNode* temp = q.front();
            treeSum(temp, sum);
            q.pop();
            if(records.find(sum) == records.end()) 
                records[sum] = 1;
            else
                records[sum]++;
            maxsum = max(maxsum, records[sum]);
            if(temp -> left)
                q.push(temp -> left);
            if(temp -> right)
                q.push(temp -> right);         
        }
        for(auto item : records) {
            if(item.second == maxsum)
                res.push_back(item.first);
        }
        
        return res;
    }
    
    void treeSum(TreeNode* root, int& sum) {
        if(root == nullptr)
            return;
        sum += root -> val;
        treeSum(root -> left, sum);
        treeSum(root -> right, sum);
    }
};

int main() {
    return 0;
}