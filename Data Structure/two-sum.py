class Solution:
    def twoSum(self, nums, target):
        seen = {}  # Dictionary to store number and its index

        for i, num in enumerate(nums):
            complement = target - num
            if complement in seen:
                return [seen[complement], i]
            seen[num] = i
