m,u,r = map(int, input().split())
dp = [[0 for i in range(u+1)] for j in range(m+1)]
for i in range(1, r+1):
    v, t, f = map(int, input().split(" "))
    for j in range(m,t-1,-1):
        for k in range(u,f-1,-1):

            dp[j][k] = max(dp[j - t][k - f]+v, dp[j][k])

print(dp[m][u])
#0-1 Knapsack Variation
