class Node:
    def __init__(self, c):
        self.val = c
        self.children = []

    def add(self, node):
        self.children.append(node)


def dfs(node, p, s):
    if p < len(s):
        for i in node.children:
            if i.val == s[p]:
                return dfs(i, p+1, s)+1
        while p < len(s):
            nxt = Node(s[p])
            node.add(nxt)
            node = nxt
            p += 1
        return 1
    return 0

#astrocat879 implementation 
