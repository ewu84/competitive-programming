class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for idx, i in enumerate(nums):
            if target-i in nums:
                if nums.index(target-i) != idx:
                    return sorted([nums.index(target-i), idx])
