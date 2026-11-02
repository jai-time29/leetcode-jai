import random

def median(nums):
    k = len(nums) // 2
    def select(l, r, k):
        p = random.randint(l, r)
        nums[p], nums[r] = nums[r], nums[p]
        pivot, i = nums[r], l
        for j in range(l, r):
            if nums[j] < pivot:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
        nums[i], nums[r] = nums[r], nums[i]
        if i == k: return nums[i]
        if i < k: return select(i + 1, r, k)
        return select(l, i - 1, k)

    if len(nums) % 2:
        return select(0, len(nums) - 1, k)
    return (select(0, len(nums) - 1, k - 1) +
            select(0, len(nums) - 1, k)) / 2



class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        nums.sort()

        n=len(nums)
        #mid=nums[int(n/2)]
        mid = median(nums)
        ans=0
        for num in nums:
            ans+=abs(num-mid)

        return int(ans)
    