import sys
input = sys.stdin.readline
from collections import deque
q = [[] for i in range(3)]
can = False;
n = int(input())
nums = list(map(int, input().split(" ")))
for i in nums:
    q[i%3].append(i)
zeroes = len(q[0])
ones = len(q[1])
twos = len(q[2])
ans = []
while len(q[0]) > 1:
    z = q[0].pop()
    ans.append(str(z))
    if ones:
       o = q[1].pop()
       ones -= 1
       ans.append(str(o))
    else:
        if twos:
            t = q[2].pop()
            ans.append(str(t))
            twos -= 1
        else:
            print("impossible")
            sys.exit()
zeroes = len(q[0])
for i in reversed(q[1]):
    ans.append(str(i))
    ones -= 1
while zeroes:
    z = q[0].pop()
    ans.append(str(z))
    zeroes -= 1
    can = True
if not(can) and ans:
    print("impossible")
    sys.exit()
for i in reversed(q[2]):
    ans.append(str(i))
print(" ".join(ans))
