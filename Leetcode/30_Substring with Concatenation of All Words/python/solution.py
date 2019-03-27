class Solution:
    # s: 字符串
    # words: 单词列表
    # return value: List[int]
    def findSubstring(self, s, words):
        ans = []
        n = len(s)
        num = len(words)
        
        if n <= 0 or num <= 0:
            return ans
            
        wordLen = len(words[0])
        
        dic = {}
        for i in range(0, num):
            if words[i] not in dic.keys():
                dic[words[i]] = 1
            else:
                dic[words[i]] += 1
        
        for i in range(0, wordLen):
            left = i
            count = 0
            tdic = {}
            for j in range (i, n-wordLen+1, wordLen):
                str = s[j:j+wordLen]
                if str in dic:
                    if str not in tdic:
                        tdic[str] = 1
                    else:
                        tdic[str] += 1
                    
                    if(tdic[str] <= dic[str]):
                        count += 1
                    else:
                        while tdic[str] > dic[str]:
                            str1 = s[left:left+wordLen]
                            tdic[str1] -= 1
                            if tdic[str1] < dic[str1]:
                                count -= 1
                            left += wordLen
                    
                    if count == num:
                        ans.append(left)
                        tdic[s[left:left+wordLen]] -= 1
                        count -= 1
                        left += wordLen
                else:
                    tdic.clear()
                    count = 0
                    left = j + wordLen
                    
        return ans
