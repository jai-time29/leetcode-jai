class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        grid = [['#']*n for _ in range(m)] #fill with hashtags
        r,c = (0,0)
        #even = True
        grid[r][c] = '.'
        while r < m - 1 or c < n - 1:
            if c < n - 1:
                c += 1
            else:
                r += 1
            grid[r][c] = '.'


        ans = [''.join(r) for r in grid]
        return ans