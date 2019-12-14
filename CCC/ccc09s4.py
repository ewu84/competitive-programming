import sys
import heapq
raw_input = sys.stdin.readline
n = int(raw_input())
adjmatrix = [[0 for x in range(n)] for y in range(n)]
t = int(raw_input())
for i in range(t):
    x,y,c = map(int, raw_input().split())
    adjmatrix[x-1][y-1] = c
    adjmatrix[y-1][x-1] = c
k = int(raw_input())
ans = []
costs = {}
for i in range(k):
    z, P = map(int, raw_input().split(" "))
    ans.append(z-1)
    costs[z-1] = P
d = int(raw_input())
d -= 1
dists = [float("inf") for i in range(n)]
dists[d] = 0
q = [[0,d]]
heapq.heapify(q)
toolong = 99999999
while q:
    time, node = heapq.heappop(q)
    if time > toolong:
        break
    for idx, c in enumerate(adjmatrix[node]):
        if c != 0:
            newdist = time + c
            if newdist < dists[idx]:
                dists[idx] = newdist
                heapq.heappush(q, [newdist, idx])
minimum = float("inf")
for i in ans:
    if (costs[i]) + dists[i] < minimum:
        minimum = (costs[i]+dists[i])
print minimum
#python 2, dijikstras
