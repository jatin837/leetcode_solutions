# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
      if root:
        if root == p or root == q:
          return root
        lh = self.lowestCommonAncestor(root.left, p, q)
        rh = self.lowestCommonAncestor(root.right, p, q)
        if lh and rh:
          return root
        if(lh):
          return lh
        return rh
      return None
      
        