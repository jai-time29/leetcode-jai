import heapq
from collections import defaultdict

class Solution:
    def minOperations(self, nums: list[int], x: int, k: int) -> int:
        small, large = [], []
        delayed = defaultdict(int)
        ss = sl = 0
        ns = nl = 0

        def prune(heap, sign):
            while heap and delayed[sign * heap[0]]:
                v = sign * heap[0]
                heapq.heappop(heap)
                delayed[v] -= 1

        def balance():
            nonlocal ss, sl, ns, nl

            if ns > nl + 1:
                prune(small, -1)
                v = -heapq.heappop(small)
                ss -= v
                sl += v
                heapq.heappush(large, v)
                ns -= 1
                nl += 1

            elif ns < nl:
                prune(large, 1)
                v = heapq.heappop(large)
                sl -= v
                ss += v
                heapq.heappush(small, -v)
                nl -= 1
                ns += 1

        def add(v):
            nonlocal ss, sl, ns, nl
            prune(small, -1)

            if not small or v <= -small[0]:
                heapq.heappush(small, -v)
                ss += v
                ns += 1
            else:
                heapq.heappush(large, v)
                sl += v
                nl += 1

            balance()

        def remove(v):
            nonlocal ss, sl, ns, nl
            prune(small, -1)
            prune(large, 1)

            delayed[v] += 1

            if v <= -small[0]:
                ss -= v
                ns -= 1
                if v == -small[0]:
                    prune(small, -1)
            else:
                sl -= v
                nl -= 1
                if large and v == large[0]:
                    prune(large, 1)

            balance()

        def get_cost():
            prune(small, -1)
            med = -small[0]
            return med * ns - ss + sl - med * nl

        # Calculate every window's cost
        costs = []
        for i, v in enumerate(nums):
            add(v)

            if i >= x:
                remove(nums[i - x])

            if i >= x - 1:
                costs.append(get_cost())

        # DP: minimum cost for selecting j windows
        n = len(nums)
        inf = float('inf')
        prev = [0] * (n + 1)

        for j in range(1, k + 1):
            cur = [inf] * (n + 1)

            for i in range(1, n + 1):
                cur[i] = cur[i - 1]

                if i >= x:
                    cur[i] = min(
                        cur[i],
                        prev[i - x] + costs[i - x]
                    )

            prev = cur

        return prev[n]
