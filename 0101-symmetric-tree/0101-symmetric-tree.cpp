# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
      def compare(node1, node2):
        if(node1 == None and node2 == None):
          return True
        if(node1 and node2 and node1.val == node2.val):
          return compare(node1.left, node2.right) and compare(node1.right, node2.left)
        return False
      return compare(root.left, root.right)