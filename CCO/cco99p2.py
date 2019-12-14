import operator


def abr(n):
    if n%10 == 1 and n%100 != 11:
        return str(n)+"st"
    if n%10 == 2 and n%100 != 12:
        return str(n)+"nd"
    if n%10 == 3 and n%100 != 13:
        return str(n)+"rd"
    return str(n)+"th"


for _ in range(int(input())):
    w, k = map(int, input().split())
    occ = {}
    for i in range(w):
        a = input()
        if a not in occ:
            occ[a] = 0
        occ[a] -= 1
    print(abr(k)+" most common word(s):")
    occ2 = sorted(occ.items(), key=operator.itemgetter(1))
    rank = 1
    smh = 1
    prev = None
    for i, x in occ2:
        if not prev == None and occ[i] != occ[prev]:
            rank = smh
        if k == rank:
            print(i)
        prev = i
        smh += 1
    print()

# this question has a couple of traps you can fall into: 
# firstly, forgetting that eleventh is not elevenst
# secondly, forgetting that if there are two elements in 1st place,
# the subsequent element is in 3rd place, not in 2nd
# RIP my AC rate
