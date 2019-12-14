n = int(input())
dpa = [0 for i in range(n)]
dpb = [0 for i in range(n)]
dpc = [0 for i in range(n)]
a,b,c = map(int, input().split())
dpa[0] = a
dpb[0] = b
dpc[0] = c
for i in range(1,n):
    a, b, c = map(int, input().split(" "))
    dpa[i] = max(dpb[i-1], dpc[i-1]) + a
    dpb[i] = max(dpa[i-1],dpc[i-1]) + b
    dpc[i] = max(dpb[i-1], dpa[i-1]) + c
print(max(dpa[n-1], dpb[n-1], dpc[n-1]))
