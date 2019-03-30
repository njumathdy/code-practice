class Solution:
    def plusOne(self, digits):
        if len(digits) < 1:
            return [1]

        j = len(digits) - 1
        while j >= 0 and digits[j] == 9:
            j -= 1

        if j == len(digits) - 1:
            digits[j] += 1
        elif j >= 0:
            digits[j] += 1
            digits[j+1:len(digits)] = 0
        else:
            digits.insert(0, 1)
            digits[1:len(digits)] = 0

        return digits

        