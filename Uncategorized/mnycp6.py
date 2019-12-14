from sys import stdin, exit
from string import ascii_lowercase
input = stdin.readline
lmi = lambda: list(map(int, input().split()))
mi = lambda: map(int, input().split())
si = lambda: input().strip('\n')
ssi = lambda: input().strip('\n').split()
mn = 10005
bit = [0]*mn
arr = [0]*mn


def strval(s):
    tot = 0
    for i in s:
        tot += ascii_lowercase.find(i) + 1
    return tot


def query(x):
    s = 0
    while x > 0:
        s += bit[x]
        x -= x & -x
    return s


def update(k, v):
    while k <= mn:
        bit[k] += v
        k += k & -k


w = dict()
i = 1
for _ in range(int(input())):
    q = ssi()
    if q[0] == "A":
        tmp = strval(q[1])
        if q[1] in w:
            print("Can't add "+q[1])
        else:
            arr[i] = tmp
            update(i, arr[i])
            w[q[1]] = i
            i += 1
    elif q[0] == "S":
        tmp1 = arr[w[q[1]]]
        tmp2 = arr[w[q[2]]]
        update(w[q[1]], -tmp1)
        update(w[q[2]], -tmp2)
        arr[w[q[1]]], arr[w[q[2]]] = arr[w[q[2]]], arr[w[q[1]]]
        w[q[1]], w[q[2]] = w[q[2]], w[q[1]]
        update(w[q[1]], arr[w[q[1]]])
        update(w[q[2]], arr[w[q[2]]])
    elif q[0] == "M":
        if w[q[2]] > w[q[1]]:
            print(query(w[q[2]]) - query(w[q[1]]-1))
        else:
            print(query(w[q[1]]) - query(w[q[2]] - 1))
    elif q[0] == "R":
        tmp2 = strval(q[2])
        update(w[q[1]], -arr[w[q[1]]])
        arr[w[q[1]]] = tmp2
        w[q[2]] = w[q[1]]
        del w[q[1]]
        update(w[q[2]], arr[w[q[2]]])
    elif q[0] == "N":
        print(len(w))
        
# Do not do this problem. It's not worth your time.
