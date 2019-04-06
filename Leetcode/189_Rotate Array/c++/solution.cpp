/*******************
Given an array, rotate the array to the right by k steps, where k is non-negative.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() <= 1)
            return;
        k = k % nums.size();
        if(k == 0) return;
        int count = 0;
        for(int start = 0; count < nums.size(); start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            }while(start != current);
        }
    }
};

int main() {
    return 0;
}