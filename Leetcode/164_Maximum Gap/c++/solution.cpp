/*******************
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.
*******************/
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// O(nlogn) time complexity
class Solution1 {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        
        int maximum = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) {
            maximum = max(maximum, nums[i]-nums[i-1]);
        }
        
        return maximum;
    }
};

// based on radix sort
class Solution2 {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.empty() || nums.size() < 2)
            return 0;

        int maxVal = *max_element(nums.begin(), nums.end());

        int exp = 1;                                 // 1, 10, 100, 1000 ...
        int radix = 10;                              // base 10 system

        vector<int> aux(nums.size());
        
        while (maxVal / exp > 0) {                   // Go through all digits from LSD to MSD
            vector<int> count(radix, 0);

            for (int i = 0; i < nums.size(); i++)    // Counting sort
                count[(nums[i] / exp) % 10]++;

            for (int i = 1; i < count.size(); i++)   // you could also use partial_sum()
                count[i] += count[i - 1];

            for (int i = nums.size() - 1; i >= 0; i--)
                aux[--count[(nums[i] / exp) % 10]] = nums[i];

            for (int i = 0; i < nums.size(); i++)
                nums[i] = aux[i];

            exp *= 10;
        }

        int maxGap = 0;

        for (int i = 0; i < nums.size() - 1; i++)
            maxGap = max(nums[i + 1] - nums[i], maxGap);

        return maxGap;
    }
};

int main() {
    return 0;
}