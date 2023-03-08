class Solution {
public:
  int calc_time(int speed, vector<int>&ps){
    int ret = 0;
    for(int p:ps)
      ret += ceil(double(p)/double(speed));
    return ret;
  }
  int minEatingSpeed(vector<int>& piles, int h) {
    int beg = 1;
    int end = *max_element(piles.begin(), piles.end());
    if(h == piles.size())
      return end;
    while(beg < end){
      int mid = beg+(end-beg)/2;
      if(calc_time(mid, piles) <= h)
        end = mid;
      else
        beg = mid+1;
    }
    return beg;
  }
};