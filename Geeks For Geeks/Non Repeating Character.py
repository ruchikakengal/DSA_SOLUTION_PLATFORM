class Solution:
    # Function to find the majority elements in the array
    def findMajority(self, arr):
        n = len(arr)
        l = []
        
        # Step 1: Use a dictionary to store frequency of each element
        frequency = {}
        for num in arr:
            if num in frequency:
                frequency[num] += 1
            else:
                frequency[num] = 1
        
        # Step 2: Check if any element appears more than n/3 times
        for num in frequency:
            if frequency[num] > (n / 3):
                l.append(num)
        
        # Step 3: Sort the result list before returning
        return sorted(l)
