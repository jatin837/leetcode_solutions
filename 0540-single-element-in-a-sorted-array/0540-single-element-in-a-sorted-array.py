## If mid is odd
##    number at mid-1 index should be equal to number at mid
##    if that's not the case, that means single element must exist on left side of array
##    If that's the case, that means single element must exist on right side of array
## If mid is even
##    number at mid+1 index should be equal to number at mid
##    if that's not the case, that means single element must exist on left side of array
##    If that's the case, that means single element must exist on right side of array           
###   if(mid%2):
###     if(nums[mid-1] == nums[mid]):
###       left = mid+1
###     else:
###       right = mid-1
###   else:
###     if(nums[mid+1] == nums[mid]):
###       left = mid+1
###     else:
###       right = mid-1
class Solution:
  def singleNonDuplicate(self, nums: List[int]) -> int:
    left, right = 0, len(nums)-1
    while(left < right):
      mid = (left+right)//2
      if(nums[mid-1] == nums[mid]):
        if(mid%2):
          left = mid+1
        else:
          right = mid-1
      elif(nums[mid+1] == nums[mid]):
        if(mid%2):
          right = mid-1
        else:
          left = mid+1
      else:
        return nums[mid]
    return nums[left]