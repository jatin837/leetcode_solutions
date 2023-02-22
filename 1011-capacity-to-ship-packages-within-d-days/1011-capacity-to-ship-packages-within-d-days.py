class Solution:
  def shipWithinDays(self, weights: List[int], days: int) -> int:
    ## Given a capacity of conveyor belt and weights, calculate the number of days to ship all package
    def calcDays(ws, cap):
      cnt, tot = 0, 0
      for w in ws:
        if(tot + w <= cap):
          tot += w
          continue
        else:
          tot = w
          cnt += 1
      return cnt+1
    
    
    ## Our solution is going to be a weight capacity
    ## The range of solution lies between [max(weights), sum(weights)]
    ## Clarification:
      ## think of what the the minimum capacity should be to ship each weight in len(weights) days
      ## think of what the the maximum capacity should be to ship all weights in one day
      ## our weight lies in above range, so the problem boils down to finding a capacity in above range such that weights are shipped in exactly desired days
      ## Hence, we are using binary search
    left, right = max(weights), sum(weights)
    while(left <= right):
      mid = (left + right)//2
      if(calcDays(weights, mid) <= days):
        right = mid-1
      else:
        left = mid+1
    return left