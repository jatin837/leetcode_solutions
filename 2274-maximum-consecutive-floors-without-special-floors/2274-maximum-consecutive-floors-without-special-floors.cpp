class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
      sort(special.begin(), special.end());   
      int ans = special[0]-bottom;
      for(int i=0; i<special.size()-1; i++)
        ans = max(special[i+1]-special[i]-1, ans);
      return max(ans, top-special[special.size()-1]);
    }
};