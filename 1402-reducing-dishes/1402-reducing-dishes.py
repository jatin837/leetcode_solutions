class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
      satisfaction.sort()
      i = len(satisfaction)-2
      while i >= 0:
        satisfaction[i] += satisfaction[i+1]
        i-=1
      i = len(satisfaction)-2
      print(satisfaction)
      while i >= 0:
        satisfaction[i] += satisfaction[i+1]
        i-=1
      print(satisfaction)
      
      return max(0, max(satisfaction))
      
      
      
      