class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
      is_anagram = []
      for i, word in enumerate(words[1:]):
        if "".join(sorted(words[i])) == "".join(sorted(word)):
          is_anagram.append(True)
        else:
          is_anagram.append(False)
      ans = []    
      ans.append(words[0])
      i=1
      while(i<len(words)):
        if is_anagram[i-1] == False:
          ans.append(words[i]) 
        i+=1;  
      return ans 
          
    