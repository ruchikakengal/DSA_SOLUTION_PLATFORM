class Solution:
    def findElements(self,arr):
        for i in range(2):
            val1 = max(arr)
            arr.remove(val1)
        
        arr.sort()
        return arr
