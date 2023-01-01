class Solution:
  def wordPattern(self, pattern: str, s: str) -> bool:
    s = s.split()
    if(len(s) != len(pattern)):
      return False;
    mp1 = defaultdict(int)
    mp2 = defaultdict(int)
    for i in range(len(pattern)):
      if(mp1[pattern[i]] != mp2[s[i]]):
        return False;
      mp1[pattern[i]] = mp2[s[i]] = i+1
    return True;