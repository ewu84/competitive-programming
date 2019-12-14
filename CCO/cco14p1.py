from sys import stdin
input = stdin.readline

n = int(input())
grid = [[0]+list(map(int, input().strip('\n').replace("#", "1").replace(".", "0")))+[0] for i in range(n)]
grid.append([0]*(n+2))
ans = 0
for i in reversed(range(n)):
    for j in range(1, n+1):
        if grid[i][j] == 1:
            grid[i][j] += min(grid[i+1][j], grid[i+1][j-1], grid[i+1][j+1])
            ans += grid[i][j]
print(ans)

# simple dp problem, watch out with indexing
