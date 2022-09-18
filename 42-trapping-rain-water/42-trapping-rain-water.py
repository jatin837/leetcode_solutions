class Solution:
    def trap(self, h: List[int]) -> int:
      N = len(h)
      if(N<=2):
        return 0
      l = [0]*N
      r = [0]*N
      l[0] = h[0]
      r[N-1] = h[N-1]
      for i in range(1, N):
        l[i] = max(l[i-1], h[i])
        r[N-i-1] = max(r[N-i], h[N-i-1])
      ret = 0;
      for i in range(N):
        ret += min(l[i], r[i]) - h[i]
      return ret
        