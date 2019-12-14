def colour(y, x, dim, f):
    global idx
    idx += 1
    if f[idx] == 'p':
        nd = dim//2
        colour(y, x + nd, nd, f)
        colour(y, x, nd, f)
        colour(y + nd, x, nd, f)
        colour(y + nd, x + nd, nd, f)
    elif f[idx] == 'f':
        for i in range(y, y + dim):
            for j in range(x, x + dim):
                grid[i][j] = True


for _ in range(int(input())):
    grid = [[False for i in range(32)] for j in range(32)]
    idx = -1
    a = input()
    colour(0, 0, 32, a)
    idx = -1
    b = input()
    colour(0, 0, 32, b)
    ans = 0
    for i in range(32):
        for j in range(32):
            if grid[i][j]:
                ans += 1
    print("There are " + str(ans) + " black pixels.")

# this is a really good recursion problem
# rather straightforward, just colour the 32x32 grid
# may require some focus when visualizing the grid
