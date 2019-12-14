import heapq
n, m = map(int, input().split(" "))
graph = {i:[] for i in range(n)}
for i in range(m):
    a, b, l = map(int, input().split(" "))
    graph[a-1].append([l,b-1])
q = [[0,0]]
dists = [[float('inf'), float("inf")] for i in range(n)]
dists[0] = [0,float('inf')]
heapq.heapify(q)
visited = set()
while q:
    time, node = heapq.heappop(q)
    for d,n in graph[node]:
        if time + d < dists[n][0]:
            dists[n][1] = dists[n][0]
            dists[n][0] = time + d
            heapq.heappush(q, [dists[n][0], n])

        elif time + d < dists[n][1] and time + d != dists[n][0]:
            dists[n][1] = time + d
            heapq.heappush(q, [dists[n][1],n])
if dists[-1][1] == float("inf"):
    print(-1)
else:
    print(dists[-1][1])
