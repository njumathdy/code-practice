class Solution:
    def jump(self, nums):
        n = len(nums)
        step, start, end = 0, 0, 0

        while end < n-1:
            step += 1
            maxend = end + 1
            for i in range(start, end+1):
                if i + nums[i] >= n - 1:
                    return step;
                maxend = max(maxend, i+nums[i])
            start = end + 1
            end = maxend

        return step
            