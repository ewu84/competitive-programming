from math import gcd
from sys import stdin
input = stdin.readline
x, y, z = map(int, input().split(" "))
n = int(input())
slopes = set()
for i in range(n):
    ax, by, cz = map(int, input().split(" "))
    agcd = gcd(gcd(ax-x, by-y), cz-z)
    slopes.add(((ax-x)//agcd, (by-y)//agcd, (cz-z)//agcd))
print(len(slopes))
