class Solution:
    def combinationSum2(self, candidates, target):
        ans = []
        temp = []
        candidates.sort()

        def dfs(now, p, target, temp, can, ans):
            if now == target:
                # 直接append(temp)是浅复制，而用temp[:]则是深复制
                ans.append(temp[:])
                return
            for i in range(p+1, len(can)):
                if now + can[i] > target: break
                if i > p + 1 and can[i] == can[i-1]:
                    continue
                temp.append(can[i])
                dfs(now+can[i], i, target, temp, can, ans)
                temp.pop()

        dfs(0, -1, target, temp, candidates, ans)
        return ans


