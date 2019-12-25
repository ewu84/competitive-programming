f = open("whereami.in", "r")
op = open("whereami.out", "w")
ii = lambda: int(f.readline())
lmi = lambda: list(map(int, f.readline().split()))
mi = lambda: map(int, f.readline().split())
si = lambda: f.readline().strip('\n')
ssi = lambda: f.readline().strip('\n').split()
n = ii()
s = si()
f.close()
for sz in range(1, n):
    j = 1
    works = True
    possi = set()
    while j+sz-1 <= n:
        sub = s[j-1:j+sz-1]
        if sub in possi:
            works = False
            break
        possi.add(sub)
        j += 1
    if works:
        op.write(str(sz) + "\n")
        break
