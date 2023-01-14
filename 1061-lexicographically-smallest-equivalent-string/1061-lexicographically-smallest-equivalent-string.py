class Solution:
  def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
    parent = list(range(26));
    def union(i, j):
      a = find(i)
      b = find(j)
      if(a < b):
        parent[b] = a
      else:
        parent[a] = b
    def find(i):
      if(parent[i] == i):
        return i;
      return find(parent[i]);
    for i in range(len(s1)):
      union(ord(s1[i])-ord('a'), ord(s2[i])-ord('a'))
    return ''.join([chr(find(ord(ch) - 97) + 97) for ch in baseStr])
      