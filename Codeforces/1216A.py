def swap(i):
    if i == 'a':
        return 'b'
    else:
        return 'a'
n = int(input())
s = list(input())
ans = 0
prev = 0
news = ''
for l in range(1, n, 2):
    sub = s[prev:l+1]
    if sub.count('a') != 1:
        ans += 1
        sub[0] = swap(sub[0])
    news += ''.join(sub)
    prev = l+1
print(ans)
print(news)
