import sys
import functools

m = int(input())
q = int(input())
memory = {}
pathsmemory = {}
def Diff(A, B):

   return (list(set(A) - set(B)))
def dp(queue, time, speeds, path):
    if not(queue):
        return [time, path]

    else:
        minimum = 999999
        minpath = []
        for length in range(m):
            newqueue = list(queue)
            group = tuple(newqueue[:length+1])
            newpath = list(path)
            newpath.append(group)

            if group in memory:
                t = memory[group]+time
                curpath = list(newpath)
                curpath.extend(pathsmemory[group])
                p = curpath
            else:
                newqueue = newqueue[length+1:]
                slowest = max([speeds[i] for i in group])
                t, p = dp(newqueue, time + slowest, speeds, newpath)

            if t < minimum:
                minimum = t
                minpath = p

            pathsmemory[group] = Diff(p, newpath)
            memory[group] = t-time
        return [minimum, minpath]
speeds = {}
queue = []
def comparator(a, b):
    occur = queue.index(a[0])
    occurb = queue.index(b[0])
    if occur > occurb:
        return 1
    else:
        return -1

cmp = functools.cmp_to_key(comparator)

for i in range(q):
    name = input()
    queue.append(name)
    speed = int(input())
    speeds[name] = speed
time, groups = dp(queue, 0, speeds, [])
print("Total Time:", str(time), sep=" ")
newgroups = sorted(groups, key=cmp)

for i in newgroups:
    print(" ".join(i))
