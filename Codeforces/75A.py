a = int(input())
b = int(input())
c = a +b
newa, newb, newc = str(a), str(b), str(c)
idx = 0
while True:
    if idx == len(newa):
        break
    if newa[idx] == '0':
        newa = newa[:idx] + newa[idx+1:]
    else:
        idx+= 1
idx = 0
while True:
    if idx == len(newb):
        break
    if newb[idx] == '0':
        newb = newb[:idx] + newb[idx+1:]
    else:
        idx+= 1
idx = 0
while True:
    if idx == len(newc):
        break
    if newc[idx] == '0':
        newc = newc[:idx] + newc[idx+1:]
    else:
        idx+= 1
if int(newa) + int(newb) == int(newc):
    print("YES")
else:
    print("NO")
