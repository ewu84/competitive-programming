from sys import exit, stdin
input = stdin.readline


def check(l):
    temp = set()
    for i in range(6):
        if l in snowflake:
            return True
        temp.add(l[i:] + l[:i])
    for i in temp:
        ri = i[::-1]
        if ri in snowflake:
            return True
    snowflake.add(l)
    snowflake.add(l[::-1])
    return False


n = int(input())
sf = [tuple(map(int, input().split())) for i in range(n)]
snowflake = set()
for s in sf:
    if check(s):
        print("Twin snowflakes found.")
        exit()
print("No two snowflakes are alike.")

# this problem is actually one of the easier 10 pointers on dmoj
# the additional data (on dmoj) fails sorting solutions, 
# so now you must use brute force

# unfortunately, I wasn't using my brain
# and submitted 25+ times before I realized:
# you do not have to push in every rotation and reverse of the flake
# this is because if 2 snowflakes are alike, you only need to turn/flip one
# to match with the other one.

# so after I noticed I stopped recieving MLE

# also lowkey I carry this github
