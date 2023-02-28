# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
    ret = []
    cnt = defaultdict(int)
    def f(node):
      if(node):
        s = f"({f(node.left)})({f(node.right)})({node.val})"
        cnt[s]+=1
        if(cnt[s] == 2):
          ret.append(node)
        return s
      return ""
    f(root)
    return ret