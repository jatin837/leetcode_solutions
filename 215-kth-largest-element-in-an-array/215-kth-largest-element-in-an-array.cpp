class Solution {
public:
//  static bool cmp(int& a, int& b){
//    return a > b;
//  }
//  int findKthLargest(vector<int>& nums, int k) {
//    sort(begin(nums), end(nums), cmp);
//    return nums[k-1];
//  }
    int findKthLargest(vector<int>& nums, int k){
      priority_queue<int> pq;
      for(int num:nums){
        pq.push(num);
        if(pq.size() > nums.size()-k+1)
          pq.pop();
      }
      return pq.top();
    }
};