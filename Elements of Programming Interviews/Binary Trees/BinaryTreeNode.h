#pragma once

#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

#include <memory>

using namespace std;

template <typename T> 
struct BinaryTreeNode {
    T data;
    unique_ptr<BinaryTreeNode<T> > left, right;
};

#endif