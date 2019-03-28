class Solution:
    def searchInsert(self, nums, target):
        if(len(nums) == 0):
            return 0

        begin, end = 0, len(nums) - 1

        while end > begin:
            middle = begin + (end - begin) // 2
            if target == nums[middle]:
                return middle
            elif target > nums[middle]:
                if middle == len(nums) - 1 or target < nums[middle+1]:
                    return middle + 1
                else:
                    begin = middle + 1
            else:
                if middle == 0 or target > nums[middle-1]:
                    return middle
                else:
                    end = middle - 1

        if target > nums[begin]:
            return begin + 1
        else:
            return begin