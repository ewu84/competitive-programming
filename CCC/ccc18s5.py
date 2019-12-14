import sys
input = sys.stdin.readline
edges = []
def find(i, graph):
    if graph[i] != i:
        graph[i] = find(graph[i],graph)
    return graph[i]
def union(x, y, rank, graph):
    rootx, rooty = find(x, graph), find(y,graph)
    if rootx == rooty:
        return False

    if rank[rootx] < rank[rooty]:
        graph[rootx] = graph[rooty]
    elif rank[rootx] > rank[rooty]:
        graph[rooty] = graph[rootx]
    else:
        graph[rootx] = graph[rooty]
        rank[rooty] += 1
    return True
tot = 0
n, m, p, q = map(int, input().split(" "))
graphP = [i for i in range(n)]
rankP = [i for i in range(n)]
graphC = [i for i in range(m)]
rankC = [i for i in range(m)]
for i in range(p):
    a,b,c = map(int, input().split(" "))
    a, b = a-1, b-1
    tot += c*n
    edges.append((c, a, b, 0))
for i in range(q):
    x, y, z = map(int, input().split(" "))
    x, y = x - 1, y - 1
    tot += z * m
    edges.append((z, x, y, 1))
edges.sort()

for w,s,d,t in edges:
    if t == 1:
        if union(s,d, rankP, graphP):
            n -= 1
            tot -=  w * m
    else:
        if union(s,d, rankC, graphC):
            m -= 1
            tot -= w * n
print(tot)
