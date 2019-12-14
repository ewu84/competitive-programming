import sys
input = sys.stdin.readline
w,h,n = map(int, input().split(" "))
grid = [list(map(int, input().split(" "))) for i in range(h)]
prefix = [[0] * (w+1) for i in range(h+1)]
for i in range(1,h+1):
    for j in range(1, w+1):
        prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] + grid[i-1][j-1] - prefix[i-1][j-1]
maxi = 0
for i in range(1,h+1):
    width = min(n//i, w)
    for j in range(1,h-i+2):
        for k in range(1,w-width+2):
            sume = prefix[j+i-1][k+width-1]-prefix[j-1][k+width-1]-prefix[j+i-1][k-1]+prefix[j-1][k-1]
            maxi = max(maxi, sume)
print(maxi)
#2-D Prefix Sum Array
