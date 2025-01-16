class Solution:
    def check(self, arr1, arr2) -> bool:
        arr1.sort()
        arr2.sort()
        return arr1==arr2
