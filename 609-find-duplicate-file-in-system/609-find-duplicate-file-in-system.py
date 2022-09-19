from collections import defaultdict
class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
      mp = defaultdict(list);
      for path in paths:
        dirr = path.split()[0]
        for file in path.split()[1:]:
          fname, cont = file.split("(")[0], file.split('(')[1]
          mp[cont].append(dirr + '/' + fname)
      ret = list();    
      for k in mp.keys():
        if(len(mp[k]) > 1):
          ret.append(mp[k])
      return ret 