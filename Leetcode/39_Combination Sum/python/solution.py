import copy

class Solution:
    def combinationSum(self, candidates, target):
        ans = []
        if len(candidates) == 0:
            return ans

        temp = []

        self.combinationSum1(candidates, target, ans, temp, 0)

        return ans

    def combinationSum1(self, candidates, target, ans, temp, start):
        for i in range(start, len(candidates)):
            temp.append(candidates[i])
            target = target - candidates[i]

            # 传引用，是浅复制，temp在后面改变之后ans中也会改变
            if target == 0:
                res = copy.deepcopy(temp)
                ans.append(res)

            if target < 0:
                target += candidates[i]
                temp.pop()
                continue

            self.combinationSum1(candidates, target, ans, temp, i)

            temp.pop()
            target += candidates[i]