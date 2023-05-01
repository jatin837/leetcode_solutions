class Solution {
public:
    double average(vector<int>& salary) {
      sort(salary.begin(), salary.end());
      double ret = accumulate(salary.begin(), salary.end(), 0) - salary[0] - salary.back();
      ret = ret/double(salary.size()-2);
      return ret;
    }
};