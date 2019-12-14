from sys import stdin, setrecursionlimit
setrecursionlimit(100000000)
input = stdin.readline


def dfs(node):
    vis[node] = True
    for i, w in graph[node]:
        if not vis[i]:
            cut[i] += w
            dfs(i)
            cut[node] += cut[i]
            val[node] += val[i]


n, c, k = map(int, input().split())
val = [0]+list(map(int, input().split()))
graph = [[]for i in range(n+1)]
for i in range(n-1):
    a, b, w = map(int, input().split())
    graph[a].append((b, w))
    graph[b].append((a, w))
vis = [False for i in range(n+1)]
cut = [0 for i in range(n+1)]
dfs(1)
ans = 0
for i in range(2, n+1):
    if cut[i] <= k and val[i] >= c:
        ans += 1
print(ans)

# i found myself running out of variable names
