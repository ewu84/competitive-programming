import sys
input = sys.stdin.readline
n = int(input())
queries = []
bit = [0 for i in range(n+1)]
arr = []
def update(idx, val):
    i = idx
    while i <= n:
        bit[i] += val
        i += i & -i

def query(idx):
    i = idx
    sum = 0
    while i > 0:
        sum += bit[i]
        i -= i & -i
    return sum
for idx, i in enumerate(map(int, input().split())):
    arr.append((i, idx+1))
q = int(input())
ans = [0] * q
arr.sort(reverse=True)
for i in range(q):
    a, b, m = map(int, input().split())
    b+=1
    a+=1
    queries.append((m, b, a, i))
queries.sort(reverse=True)
j = 0
for m, b, a, i in queries:
    while j < n and arr[j][0] >= m:
        update(arr[j][1], arr[j][0])
        j += 1
    ans[i] = query(b) - query(a-1)
for i in range(q):
    print(ans[i])
