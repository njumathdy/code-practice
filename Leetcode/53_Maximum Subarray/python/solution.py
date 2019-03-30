import sys

class Solution:
    def maxSubarray(self, nums):
        if len(nums) < 1:
            return 0

        cursum = 0
        greatestSum = -sys.maxsize

        for i in range(0, len(nums)):
            if cursum <= 0:
                cursum = nums[i]
            else:
                cursum += nums[i]

            if cursum > greatestSum:
                greatestSum = cursum

        return greatestSum