# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        q = deque([(root, "")])
        res = None

        while q:
            node, cur = q.popleft()
            cur = chr(ord('a') + node.val) + cur

            if not node.left and not node.right:
                res = min(res, cur) if res else cur

            if node.left:
                q.append((node.left, cur))
            if node.right:
                q.append((node.right, cur))

        return res