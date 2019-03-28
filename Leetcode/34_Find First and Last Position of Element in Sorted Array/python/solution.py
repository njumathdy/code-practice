class Solution:
    def searchRange(self, nums, target):
        if len(nums) == 0:
            return [-1, -1]

        l, r = 0, len(nums)-1

        while l < r:
            m = l + (r-l) // 2
            if nums[m] >= target:
                r = m
            else:
                l = m+1

        begin = l
        if nums[begin] != target:
            return [-1, -1]

        r = len(nums) - 1
        while l < r:
            m = l + (r-l)//2
            if nums[m] <= target:
                l = m+1
            else: 
                r = m
        
        end = l
        if nums[end] != target:
            end -= 1

        return [begin, end]