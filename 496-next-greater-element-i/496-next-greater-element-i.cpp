class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      vector<int>ans(nums1.size());
      stack<int>st;
      unordered_map<int, int> mapping;
      for(int i=0; i<nums2.size(); i++){
        int num = nums2[i];
        while(!st.empty() and num > st.top()){
          mapping[st.top()] = num; 
          st.pop();
        }
        st.push(num);
      }
      while(!st.empty()){
        mapping[st.top()] = -1;
        st.pop(); 
      }
      for(int i=0; i<nums1.size(); i++){
        ans[i] = mapping[nums1[i]];
      }
      return ans;
    }
};