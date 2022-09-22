from math import inf
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
      ret = -inf
      def DFS(node):
        nonlocal ret
        if(node == None):
          return 0;
        max_left = DFS(node.left);
        max_right = DFS(node.right);
        curr_max_path = node.val + max(0, max_left) + max(0, max_right)
        ret = max(ret, curr_max_path)
        return node.val + max(0, max_left, max_right)
      DFS(root)
      return ret