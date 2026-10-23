from typing import List
class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        ans=-1
        n= len(nums)
        for i in range (n) :
            if nums[i] != i :
                ans &= nums[i]
        return max(ans,0)

        