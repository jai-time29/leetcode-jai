class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        n= len(grid)
        m = len(grid[0])
        l1 = [0]*n
        l2 =[0]*m
        for i in range(n):
            for j in range(m):
                if grid[i][j]==1 :
                    l1[i]=l1[i]+1
                    l2[j]=l2[j]+1
        cnt=0
        for i in range(n):
            for j in range(m):
                if grid[i][j]==1 and (l1[i]>1 or l2[j]>1) :
                    cnt=cnt+1
        
        return cnt