from sys import stdin
from sys import setrecursionlimit
from sys import exit
input = stdin.readline
setrecursionlimit(1000000000)
n, k = map(int, input().split(" "))
graph = [[] for i in range(n)]
for i in range(n-1):
    a, b = map(int, input().split(" "))
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)
pa = [-1 for i in range(n)]
def dfs(u, p, depth):
    global maxi
    global furthest
    if depth > maxi:
        maxi = depth
        furthest = u
    pa[u] = p
    for i in graph[u]:
        if i != p:
            dfs(i, u, depth+1)
def dfsb(u, p):
    global bad
    a = 0
    b = 0
    for i in graph[u]:
        if i != p:
            if (min(u,i),max(u,i)) in bad:
                d = dfsb(i, u) - 1
            else:
                d = dfsb(i, u) + 1
            if d > a:
                b, a = a, d
            elif d > b:
                b = d
    global maxib
    maxib = max(maxib, a+b)
    return a
maxi = 0
furthest = 0
dfs(0,0,0)
maxi = 0
dfs(furthest, -1, 0)
ans = 2*(n-1) - maxi + 1
if k == 1:
    print(ans)
    exit()
cur = furthest
bad = set()
while True:
    if pa[cur] != -1:
        bad.add((min(cur, pa[cur]), max(pa[cur], cur)))
    else:
        break
    cur = pa[cur]
maxib = 0
dfsb(0, -1)
print(ans - maxib + 1)
#its back
