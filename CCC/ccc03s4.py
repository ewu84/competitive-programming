def lcp(a, b):
    s = [a, b]
    r = [len(set(c)) == 1 for c in zip(*s)] + [0]
    return s[0][:r.index(0)]

n = int(input())
for z in range(n):
    s = input()
    suffixes = []
    for char in range(len(s)):
        suffixes.append(s[char:])
    suffixes = sorted(suffixes)
    counter = 0
    for i in range(1, len(s)):
        counter += len(suffixes[i]) - len(lcp(suffixes[i - 1], suffixes[i]))
    print(counter+len(suffixes[0])+1)
#lcp, string algorithms
