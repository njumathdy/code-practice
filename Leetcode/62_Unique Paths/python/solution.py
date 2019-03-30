class Solution: 
    def uniquePaths(self, m, n):
        cur = [1] * n
         
        for i in range(1, m):
            for j in range(1, n):
                cur[j] += cur[j-1]

        return cur[j-1]