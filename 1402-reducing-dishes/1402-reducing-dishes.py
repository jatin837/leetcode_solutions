class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
      satisfaction.sort()
      def suffix_sum(nums):
        i = len(nums)-2
        while i >= 0:
          nums[i] += nums[i+1]
          i-=1
        return nums
      return max(0, max(suffix_sum(suffix_sum(satisfaction))))
      
      
      
      