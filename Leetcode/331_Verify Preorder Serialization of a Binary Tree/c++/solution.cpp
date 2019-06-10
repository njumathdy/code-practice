/*******************
One way to serialize a binary tree is to use pre-order traversal. 
When we encounter a non-null node, we record the node's value. 
If it is a null node, we record using a sentinel value such as #.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. 
Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty())
            return false;
        
        preorder += ',';
        int sz = preorder.size(),idx = 0;
        int capacity=1;
        for (idx = 0; idx < sz; idx++){
            if (preorder[idx] != ',') 
                continue;
            capacity--;
            if (capacity < 0) 
                return false;
            if (preorder[idx-1] != '#') 
                capacity += 2;
        }
        
        return capacity == 0;
    }
};

// 对于二叉树， the number of null nodes is always the number of actual nodes plus 1。
class Solution2 {
public:
    bool isValidSerialization(string preorder) {
        if (preorder == "#") return true;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < preorder.length(); ) {
            string s = "";
            while (i < preorder.length() && preorder[i] != ',') {
                s += preorder[i++];
            }
            ++i;
            if (s == "#") {
                ++c2;
            } else {
                ++c1;
            }
            if (i < preorder.length() && c1 < c2) {
                return false;
            }
        }
        return c1 + 1 == c2;
    }
};

int main() {
    return 0;
}