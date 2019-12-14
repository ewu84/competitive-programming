d = int(input())
w = [int(input()) for i in range(d)]
graph = [[] for i in range(d)]
for i in range(int(input())):
    a, b = map(int, input().split())
    graph[a-1].append(b-1)
t = int(input())
wait = [w[0]]+[-1 for i in range(d-1)]
barks = [0 for i in range(d)]
for i in range(t+1):
    newwait = [-1 for _ in range(d)]
    for j in range(d):
        if wait[j] == -1:
            continue
        if wait[j] == w[j]:
            barks[j] += 1
            for k in graph[j]:
                if wait[k] == -1:
                    newwait[k] = 1
        else:
            newwait[j] = wait[j] + 1
    wait = newwait
for i in barks:
    print(i)

# straight forward simulation
# as with most simulation problems,
# the hardest part is finding careless mistakes :(
