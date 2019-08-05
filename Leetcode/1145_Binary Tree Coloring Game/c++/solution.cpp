/*******************
Two players play a turn based game on a binary tree.  
We are given the root of this binary tree, and the number of nodes n in the tree.  
n is odd, and each node has a distinct value from 1 to n.

Initially, the first player names a value x with 1 <= x <= n, and the second player names a value y with 1 <= y <= n and y != x.  
The first player colors the node with value x red, and the second player colors the node with value y blue.

Then, the players take turns starting with the first player.  
In each turn, that player chooses a node of their color (red if player 1, blue if player 2) and colors an uncolored neighbor of the chosen node (either the left child, right child, or parent of the chosen node.)

If (and only if) a player cannot choose such a node in this way, they must pass their turn.  
If both players pass their turn, the game ends, and the winner is the player that colored more nodes.

You are the second player.  
If it is possible to choose such a y to ensure you win the game, return true.  
If it is not possible, return false.
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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if(n == 1)
            return false;
        
        TreeNode* node = search(root, x);
        int n1, n2, n3;
        
        n1 = nums(node -> left);
        n2 = nums(node -> right);
        n3 = n - 1 - n1 - n2;
        
        int maxn = max(n1, max(n2, n3));
        if(maxn > n - maxn)
            return true;
        else
            return false;
    }
    
    int nums(TreeNode* node) {
        if(node == nullptr)
            return 0;
        int res = 1;
        res += nums(node -> left);
        res += nums(node -> right);
        
        return res;
    }
    
    TreeNode* search(TreeNode* node, int x) {
        if(node == nullptr)
            return nullptr;
        
        if(node -> val == x)
            return node;
        
        if(search(node -> left, x) != nullptr)
            return search(node -> left, x);
        else
            return search(node -> right, x);
    }  
};

int main() {
    return 0;
}