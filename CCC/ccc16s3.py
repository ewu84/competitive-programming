import sys
input = sys.stdin.readline
from collections import deque
n, m = map(int, input().split(" "))
phos = set()
for i in input().split(" "):
    phos.add(int(i))
graph = {i:[] for i in range(n)}
def furthest1(start, graph):
    q = deque([[start, 0]])
    furthestnode = start
    maxdist = 0
    visited = set()
    visited.add(start)
    while q:
        node, dist = q.popleft()
        for i in graph[node]:
            if i not in visited and valid[i]:
                q.append([i, dist+1])
                visited.add(i)
        if dist > maxdist:
            maxdist = dist
            furthestnode = node
    return furthestnode
def furthest2(start, graph):
    q = deque([[start, 0]])
    maxdist = 0
    visited = set()
    visited.add(start)
    while q:
        node, dist = q.popleft()
        for i in graph[node]:
            if i not in visited and valid[i]:
                q.append([i, dist+1])
                visited.add(i)
        maxdist = max(dist, maxdist)
    return maxdist
for i in range(n-1):
    a, b = map(int, input().split(" "))
    graph[a].append(b)
    graph[b].append(a)
queue = deque([])
for i in graph:
    if len(graph[i]) == 1:
        queue.append(i)
visited = set()
subtreelength = n
valid = [True for i in range(n)]
countere = [len(graph[i]) for i in range(n)]
while queue:
    node = queue.popleft()
    if node not in visited:
        if node not in phos:
            subtreelength -= 1
            valid[node] = False
            for neighbour in graph[node]:
                countere[neighbour] -= 1
                if countere[neighbour] == 1:
                    queue.append(neighbour)
        visited.add(node)
for i in graph:
    if valid[i]:
        startnode = i
        break
f = furthest1(startnode, graph)
maxdiste = furthest2(f, graph)
print((subtreelength-1)*2-maxdiste)
#trees, bfs, and trees
