class Solution:
  def singleNonDuplicate(self, nums: List[int]) -> int:
    left, right = 0, len(nums)-1
    while(left < right):
      print(left, right)
      mid = (left+right)//2
      if(nums[mid-1] != nums[mid] and nums[mid+1] != nums[mid]):
        return nums[mid]
      ## If mid is odd
      ##    number at mid-1 index should be equal to number at mid
      ##    if that's not the case, that means single element must exist on left side of array
      ##    If that's the case, that means single element must exist on right side of array
      ## If mid is even
      ##    number at mid+1 index should be equal to number at mid
      ##    if that's not the case, that means single element must exist on left side of array
      ##    If that's the case, that means single element must exist on right side of array           
      if(mid%2):
        if(nums[mid-1] == nums[mid]):
          left = mid+1
        else:
          right = mid-1
      else:
        if(nums[mid+1] == nums[mid]):
          left = mid+1
        else:
          right = mid-1
    return nums[left]