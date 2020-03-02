class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        ans = []
        for i in nums:
            res = 0
            for j in nums:
                if j < i:
                    res+=1
            ans.append(res)
        return ans
#https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
