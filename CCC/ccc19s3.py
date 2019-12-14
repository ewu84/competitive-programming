import random
import sys
input = sys.stdin.readline
grid = [input().strip().split(" ") for i in range(3)]
counter = 0
z = 0
for i in range(3):
    for j in range(3):
        if grid[i][j] != 'X':
            grid[i][j] = int(grid[i][j])
            z = grid[i][j]
            counter += 1
if counter == 1 or all([i.count("X") == 2 and z in i for i in grid]):
    for i in range(3):
        for j in range(3):
            grid[i][j] = z
    for row in grid:
        print(" ".join([str(i) for i in row]))
    sys.exit()
def check(mat):
    for i in range(3):
        if 'X' not in grid[i]:
            if grid[i][0] + grid[i][2] != (grid[i][1] * 2):
                return False

    return True
def done(mat):
    if check(mat):
        for a,b,c in mat:
            if a == 'X' or b == 'X' or c == 'X':
                return False
        return True
    return False
def done2(mat):
    for a, b, c in mat:
        if a == 'X' or b == 'X' or c == 'X':
            return False
    return True
def help(mat):
    for i in range(9):
        if done2(mat):
            break
        for idx, row in enumerate(mat):
            a, b, c = row
            if a != 'X' and b != 'X' and c == 'X':
                mat[idx][2] = (b - a) + b
            elif a != 'X' and b == 'X' and c != 'X':
                mat[idx][1] = int(((c - a) / 2) + a)
            elif a == 'X' and b != 'X' and c != 'X':
                mat[idx][0] = b - (c - b)
    for i in range(9):
        if done2(mat):
            break
        for idx in range(3):
            a = mat[0][idx]
            b = mat[1][idx]
            c = mat[2][idx]
            if a != 'X' and b != 'X' and c == 'X':
                mat[2][idx] = (b - a) + b
            elif a != 'X' and b == 'X' and c != 'X':
                mat[1][idx] = int(((c - a) / 2) + a)
            elif a == 'X' and b != 'X' and c != 'X':
                mat[0][idx] = b - (c - b)
    if check(mat):
        return mat
    else:
        return -1
e = False
grid = help(grid)
if done(grid):
    for row in grid:
        print(" ".join([str(i) for i in row]))
    sys.exit()
if grid[1][1] == 'X':
    while True:
        past = grid
        j = help(grid)
        if done(j):
            grid = j
            e = True
            break
        grid[1][1] = random.randint(-100000, 100000)
        z = help(grid)
        if z != -1 and (all([i != 'X' for i in z[1]]) or grid[1].count("X") == 2):
            grid = z
            break
        grid = past
if done(grid) or e:
    for row in grid:
        print(" ".join([str(i) for i in row]))
    sys.exit()
sides = [(0,1), (1,0), (2,1), (1,2)]
for a,b in sides:
    if grid[a][b] == 'X':
        while True:
            past = grid
            j = help(grid)
            if done(j):
                grid = j
                e = True
                break
            grid[a][b] = random.randint(-100000,100000)
            z = help(grid)
            if z != -1 and (all([i != 'X' for i in z[a]]) or grid[a].count("X") == 2):
                grid = z
                break
            grid = past
corners = [(0,2), (2, 0), (0,0), (2,2)]
if done(grid) or e:
    for row in grid:
        print(" ".join([str(i) for i in row]))
    sys.exit()
for a,b in corners:
    if grid[a][b] == 'X':
        while True:
            past = grid
            j = help(grid)
            if done(j):
                grid = j
                e = True
                break
            grid[a][b] = random.randint(-100000,100000)
            z = help(grid)
            if z != -1 and (all([i != 'X' for i in z[a]]) or grid[a].count("X") == 2):
                grid = z
                break
            grid = past
for row in grid:
    print(" ".join([str(i) for i in row]))
#I hate this problem with passion
#Solution may not be pretty, but it gets the job done.
