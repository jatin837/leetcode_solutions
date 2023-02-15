class Solution:
  def addToArrayForm(self, num: List[int], k: int) -> List[int]:
    return list(map(int, list(str(int(''.join([str(i) for i in num])) + k))))
  