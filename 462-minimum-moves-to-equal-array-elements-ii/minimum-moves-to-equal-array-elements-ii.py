class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        nums.sort()

        n=len(nums)
        mid=nums[int(n/2)]
        ans=0
        for num in nums:
            ans+=abs(num-mid)

        return ans
    