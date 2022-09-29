class Solution:
  def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
    diff = [(abs(a-x), i) for i, a in enumerate(arr)]
    diff.sort(key = lambda a:a[0])
    ret = [arr[i] for _, i in diff[:k]]
    ret.sort()
    return ret;