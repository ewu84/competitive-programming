import heapq
class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        dists = [[float('inf') for i in range(101)] for j in range(101)]
        dirs = [[0, 1], [0,-1], [1, 0], [-1, 0]]
        q = [[0,0,0]]
        dists[0][0] = 0
        dists[0][0] = 0
        n = len(grid) - 1
        m = len(grid[0]) - 1
        while q: 
            dist, x, y = heapq.heappop(q)
            a, b = dirs[grid[x][y]-1]
            nx = x + a
            ny = y + b
            if nx >= 0 and nx <= n and ny >= 0 and ny <= m and dists[nx][ny] > dist:
                dists[nx][ny] = dist
                heapq.heappush(q, [dist,nx, ny])
            for na, nb in dirs:
                if na == a and nb == b:
                    continue
                nx = x + na
                ny = y + nb
                if nx >= 0 and nx <= n and ny >= 0 and ny <= m and dists[nx][ny] > dist+1:
                    dists[nx][ny] = dist+1
                    heapq.heappush(q, [dist+1,nx, ny])
        return dists[n][m]
           
#https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/ 
#template 
