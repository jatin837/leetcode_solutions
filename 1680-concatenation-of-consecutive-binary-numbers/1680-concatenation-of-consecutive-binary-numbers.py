class Solution:
    def concatenatedBinary(self, n: int) -> int:
      ret = 0
      shift = 0
      MOD = int(1e9+7)
      for i in range(1, n+1):
        if(i&(i-1) == 0):
          shift+=1
        ret = ((ret<<shift)|i)%MOD
      return ret