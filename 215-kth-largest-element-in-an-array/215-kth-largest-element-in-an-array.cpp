class Solution {
public:
//  static bool cmp(int& a, int& b){
//    return a > b;
//  }
//  int findKthLargest(vector<int>& nums, int k) {
//    sort(begin(nums), end(nums), cmp);
//    return nums[k-1];
//  }
//  int findKthLargest(vector<int>& nums, int k){
//    priority_queue<int, vector<int>, greater<int>> pq;
//    for(int num:nums){
//      pq.push(num);
//      if(pq.size() > k)
//        pq.pop();
//    }
//    return pq.top();
//  }
  
  int partition(vector<int>& arr, int start, int end) {
      int pivot = arr[start];
      int count = 0;
      for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
          count++;
      }
      // Giving pivot element its correct position
      int pivotIndex = start + count;
      swap(arr[pivotIndex], arr[start]);
 
      // Sorting left and right parts of the pivot element
      int i = start, j = end;
      while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
          i++;
      }
      while (arr[j] > pivot) {
        j--;
      }
      if (i < pivotIndex and j > pivotIndex) {
        swap(arr[i++], arr[j--]);
      }
    }
    return pivotIndex;
  }
  
  int QuickSelect(vector<int>& A, int start, int end, int rank){
    if(start == end)
      return A[start];
    int pividx = this->partition(A, start, end);
    if(pividx == rank)
      return A[rank];
    if(pividx < rank)
      return QuickSelect(A, pividx+1, end, rank);
    return QuickSelect(A, start, pividx-1, rank);
  }
  int findKthLargest(vector<int>& nums, int k){
    int start = 0;
    int end = nums.size()-1;
    int rank = nums.size() - k;
    return QuickSelect(nums, start, end, rank);
  }
};