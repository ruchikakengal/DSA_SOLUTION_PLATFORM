class Solution:
    def getAlternates(self, arr):
        l = []
        for i in range(len(arr)):
            if i%2==0:
                l.append(arr[i])
        return l
