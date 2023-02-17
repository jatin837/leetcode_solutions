# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def minDiffInBST(self, root: Optional[TreeNode]) -> int:
    a = []
    def inorderWalk(node):
      if(node):
        inorderWalk(node.left)
        a.append(node.val)
        inorderWalk(node.right)
    inorderWalk(root)
    return min([a[i+1]-a[i] for i in range(len(a)-1)])