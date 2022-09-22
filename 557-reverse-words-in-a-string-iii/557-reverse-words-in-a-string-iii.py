class Solution:
    def reverseWords(self, s: str) -> str:
      def wordRev(w: str):
        w = list(w)
        w.reverse()
        return ''.join(w)
      return ' '.join([wordRev(w) for w in s.split(' ')])