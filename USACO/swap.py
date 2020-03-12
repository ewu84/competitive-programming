import math
n, m, k = map(int, input().split())
arr = [i for i in range(n)]
LOG = int(math.log(k, 2)) + 1
mp = [[0 for i in range(n)] for j in range(LOG+1)]
ops = []

for i in range(m):
    l, r = map(int, input().split())
    ops.append((l-1, r-1))
for l, r in ops:
    arr = arr[:l] + arr[l:r+1][::-1] + arr[r+1:]
for i in range(n):
    mp[0][arr[i]] = i
for i in range(1, LOG+1):
    newarr = [0 for i in range(n)]
    for j in range(n):
        newarr[mp[i-1][j]] = arr[j]
        mp[i][arr[j]] = mp[i-1][j]
    arr = list(newarr)
#mp[i] wheere position i moves to
arr = [i for i in range(n)]
for i in range(LOG+1):
    if (k & (1<<i)):
        newarr = [0 for i in range(n)]
        for j in range(n):
            newarr[mp[i][j]] = arr[j]
        arr = list(newarr)
ans = []
for i in range(n):
    print(arr[i]+1)
