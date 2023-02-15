class Solution:
  def addToArrayForm(self, num: List[int], k: int) -> List[int]:
    num = int(''.join([str(i) for i in num])) + k
    return list(map(int, list(str(num))))