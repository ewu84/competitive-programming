import sys
from collections import deque
input = sys.stdin.readline
f, e = map(int, input().split())
fruits = {}
lc = {}
for i in range(f):
    a = input().strip("\n")
    fruits[a] = []
    lc[a] = 0
for i in range(e):
    o, f, w = input().split()
    w = float(w)
    fruits[o].append((w, f))

queue = deque([(1, "APPLES")])
lc["APPLES"] = 1
while queue:
    c, fruit = queue.popleft()
    if c > 1.0001 and fruit == "APPLES":
        print("YA")
        sys.exit()
    else:
        for i in fruits[fruit]:
            item = c*i[0]
            if lc[i[1]] < item:
                queue.append((item, i[1]))
                lc[i[1]] = item
print("NAW")
#BFS
