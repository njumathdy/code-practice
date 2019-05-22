/*******************
Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    stack<NestedInteger> nodes;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int size = nestedList.size();
        for(int i = size - 1; i >= 0; --i) {
            nodes.push(nestedList[i]);
        }
    }

    int next() {
        int result = nodes.top().getInteger();
        nodes.pop();
        return result;
    }

    bool hasNext() {
        while(!nodes.empty()) {
            NestedInteger curr = nodes.top();
            if(curr.isInteger()) {
                return true;
            }
        
            nodes.pop();
            vector<NestedInteger>& adjs = curr.getList();
            int size = adjs.size();
            for(int i = size - 1; i >= 0; --i) {
                nodes.push(adjs[i]);
            }
        }
    
        return false;
    }
};

int main() {
    return 0;
}