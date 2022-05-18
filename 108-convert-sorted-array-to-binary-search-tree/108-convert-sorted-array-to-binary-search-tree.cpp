/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* sortedArrayToBST(vector<int>& nums) {
      if(nums.size() == 0)
        return nullptr;
       
      int len = nums.size();
      int m = len>>1;
      
      vector<int>nums_l;
      for (int i=0; i<m; i++)
        nums_l.push_back(nums[i]);
      vector<int>nums_r;
      for (int i=m+1; i<len; i++)
        nums_r.push_back(nums[i]);
      TreeNode* root = new TreeNode(nums[m]);
      root->left = sortedArrayToBST(nums_l);
      root->right = sortedArrayToBST(nums_r);
      return root;
    }
};


//class Solution {
//public:
//    TreeNode* sortedArrayToBST(vector<int>& nums) {
//        if(nums.size()==0){
//            return NULL;
//        }
//        int len=nums.size();
//        n=n>>1;
//        vector<int> nums_l,nums_r;
//        for(int i=0;i<n;i++)
//            nums_l.push_back(nums[i]);
//        for(int i=n+1;i<nums.size();i++)
//            nums_r.push_back(nums[i]);
//        TreeNode* tnode=new TreeNode(nums[n]);
//        tnode->left=sortedArrayToBST(numsl);
//        tnode->right=sortedArrayToBST(numsr);
//        return tnode;

//    }
//};