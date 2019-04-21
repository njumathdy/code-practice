/*******************
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include "../BinaryTreeNode.h"

using namespace std;

struct BalancedStatusWithHeight {
    bool balanced;
    int height;
};

BalancedStatusWithHeight CheckBalanced(const unique_ptr<BinaryTreeNode<int> >&);

bool IsBalanced(const unique_ptr<BinaryTreeNode<int> >& tree) {
    return CheckBalanced(tree).balanced;
}

BalancedStatusWithHeight CheckedBalanced(const unique_ptr<BinaryTreeNode<int> >& tree) {
    if(tree == nullptr)
        return {true, -1};

    auto left_result = CheckedBalanced(tree -> left);
    if(!left_result.balanced)
        return {false, 0};
    auto right_result = CheckedBalanced(tree -> right);
    if(!right_result.balanced)
        return {false, 0};

    bool is_balanced = abs(left_result.height - right_result.height) <= 1;
    int height = max(left_result.height, right_result.height) + 1;
    return {is_balanced, height};
}

int main() {
    return 0;
}