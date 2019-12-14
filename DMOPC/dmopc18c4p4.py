import operator
import sys
input = sys.stdin.readline
n, q = map(int, input().split(" "))
j = 0
bit = [[0 for i in range(n+1)] for i in range(2)]
queries = []
ans = [0 for i in range(q)]
arr = []
def update(idx, val, z):
    i = idx
    while i <= n:
        bit[z][i] += val
        i += i & -i

def query(idx, z):
    i = idx
    sum = 0
    while i > 0:
        sum += bit[z][i]
        i -= i & -i
    return sum
for idx, i in enumerate(map(int, input().split(" "))):
    arr.append((i,idx+1))
    update(idx+1, i, 0)
arr.sort(key = operator.itemgetter(0))
for i in range(q):
    l, r, k = map(int, input().split(" "))
    queries.append([k, r, l, i])
queries.sort(key = operator.itemgetter(0))
for k, r, l, ids in queries:
    while j < n and arr[j][0] < k:
        update(arr[j][1], arr[j][0], 1)
        j+=1
    ans[ids] = (query(r, 0) - query(l-1, 0)) - (2 * (query(r, 1) - query(l-1, 1)))
for i in ans:
    print(i)
