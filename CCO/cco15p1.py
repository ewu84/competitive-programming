import copy
from collections import deque
n, w = map(int, input().split(" "))
crackers = deque(sorted([int(input()) for i in range(n)]))
mini = 0
if w > crackers[0] and w < crackers[-1]:
    mini = crackers[-1] - crackers[0]
else:
    mini = max(abs(w-crackers[-1]), abs(w-crackers[0]))
def maxit(next):
    crackerse = copy.deepcopy(crackers)
    ans = 0
    cur = w
    while crackerse:
        if next == 'MAD':
            node = crackerse.pop()
            next = 'LOL'
        else:
            node = crackerse.popleft()
            next = 'MAD'
        ans += max(abs(cur - node), abs(w - node))
        cur = node
    return ans

ans1 = maxit('LOL')
ans2 = maxit('MAD')
print(str(mini), str(max(ans1, ans2)))
