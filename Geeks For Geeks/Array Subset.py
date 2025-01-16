class Solution:
    def isSubset(self, a, b):
        set_a = set(a)

        for element in b:
            if element not in set_a:
                return False
        return True
