class Solution:
    def maximumBags(self, cap: List[int], rocks: List[int], extra: int) -> int:
      left = [cap[i] - rocks[i] for i in range(len(cap))]
      left.sort()
      ret = 0
      for n in left:
        extra -= n
        if(extra < 0):
          return ret
        ret += 1
      return ret;
        