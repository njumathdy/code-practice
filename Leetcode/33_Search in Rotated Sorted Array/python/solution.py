class Solution:
    def search(self, nums, target):
        l = len(nums)

        start, end= 0, l-1

        while end >= start:
            middle = (start + end) >> 1
            if nums[middle] == target:
                return middle

            if nums[middle] >= nums[start]:
                if target > nums[middle]:
                    start = middle + 1
                elif target >= nums[start]:
                    end = middle - 1
                else:
                    start = middle + 1
            else:
                if target >= nums[start] or target < nums[middle]:
                    end = middle - 1
                else:
                    start = middle + 1

        return -1
