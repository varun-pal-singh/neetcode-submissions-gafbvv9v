class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        que = deque()
        m, n = len(grid), len(grid[0])
        visited = set()
        for r in range(m):
            for c in range(n):
                if grid[r][c] == 0:
                    que.append((r, c, 0))   # row, col, curSum
                    visited.add((r, c))
        
        
        dirs = [[-1, 0], [0, -1], [1, 0], [0, 1]]
        while que:
            pr, pc, curSum = que.popleft()
            for dr, dc in dirs:
                r, c = pr + dr, pc + dc
                if (min(r, c) >= 0 and r < m and c < n and
                    (r, c) not in visited and grid[r][c] != -1):
                    visited.add((r, c))
                    grid[r][c] = min(grid[r][c], curSum + 1)
                    que.append((r, c, curSum + 1))
        
        return



"""
[
    [INF,  -1,   0, INF],
    [INF, INF, INF,  -1],
    [INF,  -1, INF,  -1],
    [0,    -1, INF, INF],
]
"""