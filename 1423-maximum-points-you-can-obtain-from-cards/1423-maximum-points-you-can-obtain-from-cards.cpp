class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int len = cardPoints.size();
      vector<int>pre(len+1);
      for(int i=0; i<len; i++)
        pre[i+1] = pre[i] + cardPoints[i];
      k = len-k;
      int b = 0;
      int e = k-1;
      int min_sum = INT_MAX;
      while(e < len){
        int sum = pre[e+1] - pre[b];
        min_sum = min(min_sum, sum);
        b++;
        e++;
      }
      int tot_sum = pre[len];
      return tot_sum - min_sum;
    }
};