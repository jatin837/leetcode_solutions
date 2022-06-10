import java.util.*;
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int max=0,curr=0;
        HashMap<Character, Integer> map = new HashMap<>();
      for(int i=0;i<s.length();i++){
        char ch = s.charAt(i);
        if(!map.containsKey(ch)){
          map.put(ch, i);
          curr++;
        }else{
          int num = i - map.get(ch);
          if(num <= curr + 1) curr = num;
          else curr++;
          map.put(ch, i);
        }
        max = Math.max(curr, max);
      }
      return max;
    }
}