class Solution:
  def shipWithinDays(self, weights: List[int], days: int) -> int:
    def calcDays(ws, cap):
      cnt = 0
      tot = 0
      for w in ws:
        if(tot + w <= cap):
          tot += w
          continue
        else:
          tot = w
          cnt += 1
      return cnt+1
    left = max(weights)
    right = sum(weights)
    while(left <= right):
      mid = (left + right)//2
      if(calcDays(weights, mid) <= days):
        right = mid-1
      else:
        left = mid+1
    return left