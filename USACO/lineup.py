from collections import deque
ii = lambda: int(f.readline())
lmi = lambda: list(map(int, f.readline().split()))
mi = lambda: map(int, f.readline().split())
si = lambda: f.readline().strip('\n')
ssi = lambda: f.readline().strip('\n').split()
f = open("lineup.in", "r")
op = open("lineup.out", "w")

n = ii()
arr = ["Beatrice", "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"]
arr.sort()
mustbe = {}
for i in range(n):
    a, z, x, y, k, b = ssi()
    if a in mustbe:
        mustbe[a].append(b)
    else:
        mustbe[a] = [b]
    if b in mustbe:
        mustbe[b].append(a)
    else:
        mustbe[b] = [a]
for i in range(8):
    if arr[i] not in mustbe or len(mustbe[arr[i]]) == 1:
        start = arr[i]
        break
q = deque([start])
vis = set()
vis.add(start)
while q:
    cur = q.popleft()
    op.write(cur+'\n')
    ct = 0
    if cur in mustbe:
        z = sorted(mustbe[cur])
        for i in z:
            if i not in vis:
                q.append(i)
                vis.add(i)
                ct += 1
    if not(ct):
        for i in range(8):
            if arr[i] not in vis:
                if (arr[i] not in mustbe):
                    q.append(arr[i])
                    vis.add(arr[i])
                    break
                else:
                    counter = 0
                    for j in mustbe[arr[i]]:
                        if j not in vis:
                            counter += 1
                    if counter == 1:
                        q.append(arr[i])
                        vis.add(arr[i])
                        break
f.close()
#:sob:
