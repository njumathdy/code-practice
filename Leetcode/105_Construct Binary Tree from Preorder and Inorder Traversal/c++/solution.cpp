/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归解法
class Solution1 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return create(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);       
    }
    
    TreeNode* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){  
        if(ps > pe){
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[ps]);
        int pos;
        for(int i = is; i <= ie; i++){
            if(inorder[i] == node->val){
                pos = i;
                break;
            }
        }
        node->left = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
        node->right = create(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);
        return node;
    }
};

// 迭代解法
class Solution2 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)
            return nullptr;
     
        stack<TreeNode*> st;
        TreeNode *t,*r,*root;
        int i,j;
        int f; // flag: 表明是左子节点还是右子节点
     
        f=i=j=0;
     
        root = new TreeNode(preorder[i]);
        st.push(root);
        t = root; // t表示当前要处理的节点
        i++;
     
        while(i<preorder.size())
        {
            if(!st.empty() && st.top()->val==inorder[j])
            {
                t = st.top();
                st.pop();
                f = 1;
                j++;
            }
            else
            {
                if(f==0)
                {
                    t -> left = new TreeNode(preorder[i]);
                    t = t -> left;
                    st.push(t);
                    i++;
                }
                else 
                {
                    f = 0;
                    t -> right = new TreeNode(preorder[i]);
                    t = t -> right;
                    st.push(t);
                    i++;
                }
            }
        }
     
        return root;      
    }    
};

int main() {
    return 0;
}