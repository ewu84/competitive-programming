import heapq
import sys
input = sys.stdin.readline
n = int(input())
p = list(map(int, input().split(" ")))
if n == 1 and p == [1]:
    print(1)
    print(1)
else:
    mini = 0
    newp = []
    ones = 0
    twos = 0
    for i in p:
        if i == 1:
            ones += 1
        elif i == 2:
            twos += 1
        else:
            heapq.heappush(newp, i)
    print((max((sum(newp) + twos*2), 1)) % 1000000007)
    for i in range(n-1):
        if ones and twos:
            heapq.heappush(newp,3)
            ones, twos = ones-1, twos-1
        elif ones >= 2:
            ones -= 2
            twos += 1
        elif ones >= 1:
            n = heapq.heappop(newp)
            ones -= 1
            n += 1
            heapq.heappush(newp,n)
    
        else:
            break
    
    maxi = 1
    for i in newp:
        maxi *= i
    for i in range(twos):
        maxi *= 2
    print(maxi%1000000007)
#greedy algorithm
