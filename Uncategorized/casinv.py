from sys import stdin, exit
from bisect import bisect_left
input = stdin.readline
lmi = lambda: list(map(int, input().split()))
mi = lambda: map(int, input().split())
si = lambda: input().strip('\n')
ssi = lambda: input().strip('\n').split()


n = int(input())
arr = sorted(lmi())
arr2 = sorted(lmi())
psa = [0]
for i in range(n):
    psa.append(psa[-1]+arr[i])
ans = 0
if arr[n-1] == arr2[n-1]:
    for i in arr2:
        res = bisect_left(arr, i)
        ans += (n-res)*i
        ans += psa[res]
else:
    ans = -1
print(ans)

# thanks to 4fecta and yanda for setting a great problem :) !!
