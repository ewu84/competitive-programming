import sys
raw_input = sys.stdin.readline
n, m, d = map(int,raw_input().split())
graph = [i for i in range(n+1)]
edges = []
for i in range(m):
    a,b,c = map(int, raw_input().split())
    edges.append((c,i,a,b))
edges.sort()
def find(a):
    root = a
    while root != graph[root]:
        root = graph[root]
    while a != root:
        a, graph[a] = graph[a], root
    return root
days = 0
nodes = 0
w = 0
for i in range(m):
    c, z, x, y = edges[i]
    rootx = find(x)
    rooty = find(y)
    if rooty != rootx:
        w = c
        if z >= n-1:
            days += 1
        nodes += 1
        graph[rootx] = rooty
        if nodes == n-1:
            break
if edges[i][1] >= n-1:
    graph = [i for i in range(n+1)]
    rank = [i for i in range(n+1)]
    for c,z,x,y in edges:
        rootx = find(x)
        rooty = find(y)
        if rooty == rootx:
            continue
        if c < w or (z < n-1 and c == w):
            if rank[rootx] < rank[rooty]:
                graph[rootx] = graph[rooty]
            elif rank[rootx] > rank[rooty]:
                graph[rooty] = graph[rootx]
            else:
                graph[rootx] = graph[rooty]
                rank[rooty] += 1
        elif c <= d and (z < n-1):
            days -= 1
            break
print days
#Python 2, MST-Kruskals
