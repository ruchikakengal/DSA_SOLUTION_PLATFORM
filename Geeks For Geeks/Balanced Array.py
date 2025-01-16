class Solution:
    def min_value_to_balance(self, arr):
        x = int(len(arr) / 2)
        left = arr[:x]
        right = arr[x:]
        res = sum(left) - sum(right)
        return abs(res)
