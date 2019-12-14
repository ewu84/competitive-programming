dicte = {}
n = int(input())
for i in range(1, n+1):
    line = list(map(int, input().split(" ")))
    if line == 0:
        line = []
    else:
        justinz = line.pop(0)
    dicte[i] = line
def bfs(start, dicte, n):
    queue = [[start]]
    visited = []
    shortestpath = 0
    while queue:
        path = queue.pop(0)
        node = path[-1]
        if not(dicte[node]):
            if not(shortestpath):
                shortestpath = len(path)


        for neighbour in dicte[node]:
            if neighbour not in visited and neighbour != 1:
                newpath = list(path)
                newpath.append(neighbour)
                queue.append(newpath)
                visited.append(neighbour)
    return[n-1-len(visited), shortestpath]
a = bfs(1, dicte, n)
if a[0] == 0:
    print("Y")
else:
    print("N")
print(a[1])
