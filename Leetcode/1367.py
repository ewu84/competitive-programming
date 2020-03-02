# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        arr = []
        cur = head
        while True:
            arr.append(cur.val)
            cur = cur.next
            if cur == None:
                break
        dp = {}
        start = []
        def dfs(node):
            if node.val == arr[0]:
                start.append(node)
            lft = node.left
            rt = node.right
            if lft:
                dfs(lft)
            if rt:
                dfs(rt)
        dfs(root)
        def dfs2(node, idx, lens):
            if idx == lens-1:
                return True
            if (node, idx) in dp:
                return dp[(node, idx)]
            lft = node.left
            rt = node.right
            can = False
            if lft and lft.val == arr[idx+1]:
                can = can or dfs2(lft, idx+1, lens)
            if rt and rt.val == arr[idx+1]:
                can = can or dfs2(rt, idx+1, lens)
            dp[(node, idx)] = can
            return can
        lens = len(arr) 
        for i in start:
            if dfs2(i, 0, lens):
                return True
        return False
#dp isnt needed 
#https://leetcode.com/problems/linked-list-in-binary-tree/
#wasted 30 mins on this :/
    
            
