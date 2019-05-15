/*******************
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
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
    void reverseString(vector<char>& s) {
        if(s.size() < 2)
            return;
        
        int n = s.size();
        int i = 0, j = n - 1;
        while(i < j) {
            swap(s[i], s[j]);
            i++; j--;
        }
        
        return;
    }
};

int main() {
    return 0;
}