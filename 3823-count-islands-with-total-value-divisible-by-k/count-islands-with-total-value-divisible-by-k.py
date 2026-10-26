class Solution:
    def returnSum(self, grid, r, c):
        m, n = len(grid), len(grid[0])
        s = grid[r][c]
        grid[r][c] = 0
        st = [(r, c)]

        while st:
            x, y = st.pop()
            for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                a, b = x + dx, y + dy
                if 0 <= a < m and 0 <= b < n and grid[a][b] > 0:
                    s += grid[a][b]
                    grid[a][b] = 0
                    st.append((a, b))
        return s

    def countIslands(self, grid: List[List[int]], k: int) -> int:
        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] > 0:
                    if self.returnSum(grid, i, j) % k == 0:
                        ans += 1
        return ans
