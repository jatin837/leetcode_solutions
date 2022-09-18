class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      vector<int>L(heights.size(), -1), R(heights.size(), heights.size());
      stack<int>st1, st2;
      for(int i=heights.size()-1; i>=0; i--){
        while(!st1.empty() && heights[i] < heights[st1.top()]){
          L[st1.top()] = i;
          st1.pop();
        }
        st1.push(i);
      }
      for(int i=0; i<heights.size(); i++){
        while(!st2.empty() && heights[i] < heights[st2.top()]){
          R[st2.top()] = i;
          st2.pop();
        }
        st2.push(i);
      }
 //   for(int n:L)
 //     cout<<n<<' ';
 //   cout<<"\n";
 //   for(int n:R)
 //     cout<<n<<' ';
 //   cout<<"\n";
      int ret = 0;
      for(int i=0; i<heights.size(); i++)
        ret = max(ret, ((R[i]-L[i])-1)*heights[i]);
      return ret;
    }
};