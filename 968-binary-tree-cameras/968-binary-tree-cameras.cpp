/*
  solve function takes a tree node pointer and returns the an array of size three
  =====================================================================
  arr[0] => minimum number of cameras from bottom of tree upto this node such that neither this node is covered with camera nor monitored but it's subtree and monitored
  arr[1] => minimum number of cameras from bottom of tree upto this node such that this node is not covered with camera, but this as well as it's subtrees are monitored completely
  arr[2] => minimum number of cameras from bottom of tree upto this node such that this node is covered with camera and it's subtrees are completely monitored
  
  The Base Case
  =============
  if i have an empty tree, then minimum number of cameras i need to monitor left and right subtrees and not place camera at root node is 0
  the above statement covers arr[0] and arr[1] for this base case
  not, if i place a camera here at the root, this is not possible, because there is no tree at all, so arr[2] should be infinite
  the answer of this problems is minimum of arr[2] and arr[3] for root node
  
  
  
  This was a pretty clever problem, and leetcode solution was very impressive.
  It was in java & python, so implemented it in c++.
*/
class Solution {
public:
    array<int, 3> solve(TreeNode* root){
      if(root == nullptr)
        return {0, 0, 1001};
      array<int, 3> left = solve(root->left);
      array<int, 3> right = solve(root->right);
      int mL12 = min(left[1], left[2]);
      int mR12 = min(right[1], right[2]);
      int d0 = left[1] + right[1];
      int d1 = min(left[2] + mR12, right[2] + mL12);
      int d2 = 1+min(left[0], mL12) + min(right[0], mR12);
      return {d0, d1, d2};
    }
    int minCameraCover(TreeNode* root) {
      array<int, 3> ans = solve(root);
      return min(ans[1], ans[2]);
    }
};