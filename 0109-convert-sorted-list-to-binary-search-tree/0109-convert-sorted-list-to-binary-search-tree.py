# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
      nums = []
      while(head):
        nums.append(head.val)
        head = head.next
      def build_tree(beg, end):
        if(beg > end):
          return None
        mid = beg + (end-beg)//2
        root = TreeNode(nums[mid], build_tree(beg, mid-1), build_tree(mid+1, end))
        return root
      return build_tree(0, len(nums)-1)