class Solution:
    def canJump(self, nums):
        lastPos = len(nums) - 1
        
        for j in range(len(nums)-1, -1, -1):
            if j + nums[j] >= lastPos:
                lastPos = j
                
        return lastPos == 0