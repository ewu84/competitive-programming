import sys
input = sys.stdin.readline
import math
n = int(input())
total = 0
while n != 1:
    b = -1
    for i in range(2, int(math.sqrt(n))+1):
        if n%i == 0:
            b = i
            break
    if b != -1:
        a = n/b
        n -= a
        total += n/a
    else:
        n -= 1
        total += n
print(int(total))
#Greedy 
