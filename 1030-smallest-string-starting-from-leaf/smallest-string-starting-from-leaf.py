# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        def dfs(root, cur):
            if not root:
                return

            cur = chr(ord('a') + root.val) + cur
            if root.left and root.right:
                return min(
                    dfs(root.left, cur),
                    dfs(root.right, cur)
                )

            if root.right:
                return dfs(root.right, cur)
            if root.left:
                return dfs(root.left, cur)
            return cur

        return dfs(root, "")