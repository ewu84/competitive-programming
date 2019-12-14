import heapq
m, v, e = map(int, input().split())
graph = [[] for j in range(v)]
for i in range(e):
    a, b, t, h = map(int, input().split())
    graph[a-1].append([t, b-1, h])
    graph[b-1].append([t, a-1, h])
start, end = map(int, input().split())
start, end = start-1, end-1
visited = set()
dists = [[999999999 for i in range(m)] for j in range(v)]
dists[start] = [0 for i in range(m)]
que = [(0, start, 0)]  # time, node, damage
mintime = -1
while que:
    time, node, hull = heapq.heappop(que)
    if node == end:
        mintime = time
        break
    if (time, node) in visited:
        continue
    visited.add((time, node))
    for t, n, d in graph[node]:
        if hull + d < m and dists[n][d+hull] > dists[node][hull] + t:
            newdist = dists[node][hull] + t
            dists[n][d+hull] = newdist
            heapq.heappush(que, (newdist, n, hull+d))
print(mintime)
#dijikstra
