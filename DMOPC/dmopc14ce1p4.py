import sys
input = sys.stdin.readline
import heapq
v = int(input())
e = int(input())
graph = {i:[] for i in range(1,v+1)}
for i in range(e):
    m,n,d,s = map(int, input().split(" "))
    graph[m].append([n,float(d),float(s)])
    graph[n].append([m,float(d),float(s)])
dists = [float("inf") for i in range(v)]
edges = [float("inf") for i in range(v)]
ogdists = [float("inf") for i in range(v)]
dists[0] = 0
edges[0] = 0
ogdists[0] = 0
q = [[0.0, 1, 0]]
while q:
    time, node, edge = heapq.heappop(q)
    for n, d, s in graph[node]:
        newdist = time + ((d/s)*60.0)
        if newdist < ogdists[n-1]:
            ogdists[n-1] = newdist
            edges[n-1] = edge+1
            dists[n-1] = dists[node-1] + ((d/(s*0.75))*60.0)
            heapq.heappush(q, [newdist, n, edge+1])
        elif newdist == ogdists[n-1] and edge+1 < edges[n-1]:
            edges[n-1] = edge+1
            heapq.heappush(q, [newdist, n, edge+1])
print(edges[-1])

print(int(round(dists[-1]-ogdists[-1])))
#Dijikstras
