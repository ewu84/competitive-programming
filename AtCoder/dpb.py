import sys
input = sys.stdin.readline
n, k = map(int, input().split())
heights = list(map(int, input().split()))
dp = [float("inf") for i in range(n+2)]
dp[0] = 0
for i in range(1,n):
    for j in range(1,k+1):
        if i-j < 0:
            break
        dp[i] = min(dp[i], dp[i-j] + abs(heights[i] - heights[i-j]))
print(dp[n-1])
#submit in pypy
#does not pass on dmoj.
