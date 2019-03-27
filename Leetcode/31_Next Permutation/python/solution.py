class Solution:
    def nextPermutation(self, nums):
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) == 1:
            return 
        
        i = len(nums) - 2
        while i >= 0 and nums[i] >= nums[i+1]:
            i -= 1
            
        if i >= 0:
            j = len(nums) - 1
            while j > i and nums[j] <= nums[i]:
                j -= 1    
            self.swap(nums, i, j)
            
        self.reverse(nums, i+1)
        
    def reverse(self, nums, start):
        i, j = start, len(nums) - 1
        while j > i:
            self.swap(nums, i, j)
            i += 1
            j -= 1
              
    def swap(self, nums, i, j):
        temp = nums[i]
        nums[i] = nums[j]
        nums[j] = temp