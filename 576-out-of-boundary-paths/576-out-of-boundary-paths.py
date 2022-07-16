from collections import defaultdict
class Solution:
    def findPaths(self, m: int, n: int, N: int, x: int, y: int) -> int:
      mod: int = int(1e9+7)
      dp1 = defaultdict(int)
      dp1[(x, y)]=1 
      cnt: int = 0
      for i in range(0, N+1):
        dp2 = defaultdict(int)
        for xi, yi in dp1:
          if (xi == -1 or xi == m or yi == -1 or yi == n):
            cnt += dp1[(xi, yi)]%mod
          else:
            dp2[(xi-1, yi)] += dp1[(xi, yi)]%mod
            dp2[(xi+1, yi)] += dp1[(xi, yi)]%mod
            dp2[(xi, yi+1)] += dp1[(xi, yi)]%mod
            dp2[(xi, yi-1)] += dp1[(xi, yi)]%mod
        dp1 = dp2
      return cnt%mod
          
      