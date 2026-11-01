class Solution:
    def minMoves(self, nums: list[int]) -> int:
        ans=0
        if len(nums)==1 :
            return 0
        mini=1e8
        for num in nums:
            mini=min(mini,num)
        for num in nums:
            ans+=abs(num-mini)
        return ans