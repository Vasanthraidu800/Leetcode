class Solution(object):
    def largestGoodInteger(self, num):
        """
        :type num: str
        :rtype: str
        """
        sub = ""
        n = len(num)

        for i in range(n - 2):
            if num[i] == num[i+1] == num[i+2]:
                temp = num[i:i+3]
                if  temp > sub:
                    sub = temp
        return sub
