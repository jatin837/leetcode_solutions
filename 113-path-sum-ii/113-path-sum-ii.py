from copy import copy
class Solution:
  def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
    ret = []
    def dfs(tmp, _sum, node):
      nonlocal ret;
      _sum += node.val
      tmp.append(node.val)
      if(node.left):
        dfs(tmp.copy(), _sum, node.left)
      if(node.right):
        dfs(tmp.copy(), _sum, node.right)
      if(node.left == None and node.right == None):
        if(_sum == targetSum):
          ret.append(tmp)
    if(root):      
      dfs([], 0, root)
    return ret