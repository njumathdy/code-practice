/*******************
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <stack>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// 递归解法
class Solution1 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return createTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    
    TreeNode* createTree(vector<int>& inorder, vector<int>& postorder, int s1, int e1, int s2, int e2) {
        if(s1 > e1 || s2 > e2)
            return nullptr;
        
        int root = postorder[e2];
        TreeNode* pRoot = new TreeNode(root);
        int i = 0;
        while(inorder[i] != root)
            i++;
        
        pRoot -> left = createTree(inorder, postorder, s1, i-1, s2, s2-s1+i-1);
        pRoot -> right = createTree(inorder, postorder, i+1, e1, e2-e1+i, e2-1);
        
        return pRoot;
    }
};

// 迭代解法：从后向前迭代，因此每次先连接右节点，再连接左节点。
class Solution2 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()) return NULL;
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        int i = postorder.size() - 2, j = i+1, k = 0;
        TreeNode* node = root;
        stack<TreeNode*> st;
        st.push(root);
        while(i >= 0){
            if(!st.empty() && st.top() -> val == inorder[j]){
                node = st.top();
                st.pop();
                j--;
                k = 1;
            }
            else{
                if(k){
                   k = 0;
                   node -> left = new TreeNode(postorder[i--]);
                   node = node -> left;
                   st.push(node);
                }
                else{
                    node -> right = new TreeNode(postorder[i--]);
                    node = node -> right;
                    st.push(node);
                }
            }
        }
        return root;
    }   
};
int main() {
    return 0;
}