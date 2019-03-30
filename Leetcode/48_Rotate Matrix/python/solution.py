class Solution:
    def rotate(self, matrix):
        for i in range(0, len(matrix)):
            for j in range(0, i+1):
                temp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = temp

        for i in range(0, len(matrix)):
            matrix[i].reverse()

        # list.reverse()是将原列表反序，reversed()是返回一个迭代器，不改变原来列表的顺序