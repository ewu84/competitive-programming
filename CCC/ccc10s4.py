from sys import stdin
input = stdin.readline


def find(z):
    root = z
    while root != graph[root]:
        root = graph[root]
    while z != root:
        z, graph[z] = graph[z], root
    return root


m = int(input())
ee = [set() for i in range(m+1)]
edges = []
edges2 = []
n = 1
for i in range(1, m+1):
    temp = list(map(int, input().split()))
    e = int(temp[0])
    nodes = temp[1:e+1]
    weights = temp[e+1:]
    for j in range(e):
        ne = (weights[j-1], min(nodes[j],nodes[j-1]), max(nodes[j],nodes[j-1]))
        found = False
        for k in range(1, i+1):
            if ne in ee[k]:
                n += 1
                edges.append((ne[0], k, i))
                edges2.append((ne[0], k, i))
                ee[k].remove(ne)
                found = True
                break
        if not found:
            ee[i].add(ne)

for node, i in enumerate(ee):
    for w, a, b in i:
        edges2.append((w, node, 0))
# print(edges)


graph = [i for i in range(n+1)]
edges.sort()
e, cnt = 0, 0
for c, a, b in edges:
    roota, rootb = find(a), find(b)
    if roota != rootb:
        graph[roota] = rootb
        cnt += c
        e += 1
        if e == n - 1:
            break
ans1 = cnt


graph = [i for i in range(n+1)]
edges2.sort()
e, cnt = 0, 0
for c, a, b in edges2:
    roota, rootb = find(a), find(b)
    if roota != rootb:
        graph[roota] = rootb
        cnt += c
        e += 1
        if e == n:
            break
ans2 = cnt

print(min(ans1, ans2))

# difficult part is building the graph, treat the "outside" as another node
# connect all other edges to outside
