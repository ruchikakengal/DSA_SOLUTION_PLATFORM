class Solution:
    def multiply(self, arr):
        # Code here
        n = len(arr) // 2
        return sum(arr[:n]) * sum(arr[n:])
