/*******************
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <limits.h>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 这里主要采用中序排序来解决该问题
// 注意在二叉搜索树中，中序遍历得到的序列一定是前面的数比后面的数小。
// 所以若我们遍历中序序列，有prev->val >= curr->val，则prev一定是第一个错误的节点，
// 继续遍历，第二个错误的节点一定是较大的节点，所以若我们找到prev->val > curr->val这样的节点对，
// 则更新第二个节点。最后交换两个节点的值即可。

// recursive
class Solution1 {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    
    void recoverTree(TreeNode* root) {
        help(root);
        swap(first->val, second->val);
    }
    
    void help(TreeNode* root){
        if(root==nullptr)  
            return;
        
        help(root->left);
        if(prev != nullptr && prev->val >= root->val) {
            if(first == nullptr)
                first = prev;
            second = root;
        }
        
        prev = root;
        help(root->right);
    }
};

class Solution2 {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev   = nullptr;
        TreeNode* first  = nullptr;
        TreeNode* second = nullptr;
        
        stack<TreeNode*> stk;
        while (!stk.empty() || root)
        {
            while (root)
            {
                stk.push(root);
                root = root->left;
            }
            
            root = stk.top();stk.pop();
            
            if (prev && prev->val >= root->val)
            {
                first  = first ? first : prev;
                second = root;
            }
            
            prev = root;
            root = root->right;
        }
        
        if (first && second)
            swap(first->val, second->val);
    }
};

// Morris traversal
class Solution3 {
public: 
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr;
        TreeNode *prev = nullptr, *pred = nullptr;
        TreeNode *curr = root;

        while(curr != nullptr) {
            if(prev != nullptr && prev->val >= curr->val) {
                if(first == nullptr)
                    first = prev;
                second = curr;
            }

            if(curr->left != nullptr) {
                pred = curr->left;
                while(pred->right != nullptr && pred->right != curr) {
                    pred = pred -> right;
                }
                if(pred->right == nullptr) {
                    pred -> right = curr;
                    curr = curr -> left;
                } else {
                    pred -> right = nullptr;
                    prev = curr;
                    curr = curr -> right;
                }
            } else {
                prev = curr;
                curr = curr -> right;
            }
        }
        swap(first->val, second->val);
    }
};

int main() {
    return 0;
}