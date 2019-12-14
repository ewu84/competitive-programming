import sys
input = sys.stdin.readline
n, t = map(int, input().split(" "))
dp = [0] * (t+1)

for i in range(1, n+1):
    p, pi, a, ai, g, gi = map(int, input().split(" "))
    for j in range(t,p-1, -1):
        if j >= p:
            dp[j] = max(dp[j], dp[j - p] + pi)
        if j >= a:
            dp[j] = max(dp[j], dp[j-a]+ai)
        if j >= g:
            dp[j] = max(dp[j], dp[j-g]+gi)
print(dp[t])
#0-1 Knapsack Variation
