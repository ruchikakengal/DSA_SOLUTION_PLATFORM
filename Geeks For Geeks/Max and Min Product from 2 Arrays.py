class Solution:
    # Function to find the maximum element from array arr1 and 
    # the minimum element from array arr2 and return their product.
    def find_multiplication(self, arr1, arr2):
        # code here
        max_ele = max(arr1)
        min_ele = min(arr2)
        return max_ele * min_ele
