class Solution:
  def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
    pts = [(b[0], -b[2]) for b in buildings] + [(b[1], b[2]) for b in buildings]
    pts.sort()
    curr = 0
    prev = 0
    ht = [0]
    ret = []
    for pt in pts:
      if(pt[1] < 0):
        ht.append(-pt[1])
      else:
        ht.remove(pt[1])
      ht.sort()
      curr = ht[-1]
      if(curr != prev):
        ret.append([pt[0], curr])
        prev = curr
    return ret