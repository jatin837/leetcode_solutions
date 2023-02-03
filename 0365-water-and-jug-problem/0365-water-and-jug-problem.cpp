class Solution {
public:
  bool canMeasureWater(int jc1, int jc2, int tc) {
    if(jc1 == tc || jc2 == tc)
      return true;
    if(jc1 + jc2 < tc)
      return false;
    return tc%gcd(jc1, jc2) == 0;
  }
};