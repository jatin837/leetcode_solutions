class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
      vector<bool>sorted(strs[0].size(), true);
      for(int i=1; i<strs.size(); i++)
        for(int j=0; j<strs[i].size(); j++)
          sorted[j] = sorted[j] && (strs[i][j] >= strs[i-1][j]);
      return count(sorted.begin(), sorted.end(), false);
    }
};