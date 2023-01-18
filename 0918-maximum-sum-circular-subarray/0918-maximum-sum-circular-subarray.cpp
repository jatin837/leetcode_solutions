class Solution {
public:

  int maxSubarraySumCircular(vector<int>& arr) {
    // find the subarray sum which is maximum(s1) and minimum(s2)
    // than, return the max of (s1, s-s2)
    // where s is the sum of the whole array
    // if s-s2 == 0 => complete array is negetive
    // in such a case, the algorithm will try to remove all the elements from array
    // which is not allowed in the problem statement
    int s1 = arr[0];
    int b1 = arr[0];
    int s2 = arr[0];
    int b2 = arr[0];
    int s = arr[0];
    for(int i=1; i<arr.size(); i++){
      s1 = max(arr[i], s1 + arr[i]);
      b1 = max(s1, b1);
      s2 = min(arr[i], s2 + arr[i]);
      b2 = min(s2, b2);
      s += arr[i];
    }
    s1=b1;
    s2=b2;
    return (s2==s)?s1:max(s1, s-s2);
  }
};