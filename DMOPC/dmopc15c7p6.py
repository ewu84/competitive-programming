def palen(string):
    length = len(string)
    lens = []
    cur = 0
    curlen = 0
    while cur < length:
        if cur > curlen and string[cur - curlen - 1] == string[cur]:
            curlen += 2
            cur += 1
            continue
        lens.append(curlen)
        start = len(lens) - 2
        end = start - curlen
        for i in range(start, end, -1):
            need = i - end - 1
            if lens[i] == need:
                curlen = need

                break
            lens.append(min(need, lens[i]))
        else:
            curlen = 1
            cur += 1
    lens.append(curlen)
    total = len(lens)
    start = total - 2
    end = start - (2 * length + 1 - total)
    for i in range(start, end, -1):
        need = i - end - 1
        lens.append(min(need, lens[i]))
    return lens
total = 0
s = input()
arr = palen(s)
a = [0 for i in range((len(s)*2+1)+1)]
b = [0 for i in range((len(s)*2+1)+1)]
for i in range(len(s)*2+1):
    a[i] += 1
    b[i+1] -= 1
    a[i+arr[i]] -= 1
    b[i-arr[i]+1] += 1
for i in range(1, len(s)*2+1):
    a[i] += a[i-1]
    b[i] += b[i-1]
for i in range(3, len(s)*2+1, 2):
    a[i] += a[i-2]
for i in range(3, len(s)*2+1, 2):
    total += b[i] * a[i-2]
print(total)
