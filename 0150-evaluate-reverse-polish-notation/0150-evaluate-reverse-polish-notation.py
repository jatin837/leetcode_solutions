class Solution:
  def evalRPN(self, tokens: List[str]) -> int:
    st = list()
    st.append(tokens[0])
    for ch in tokens[1:]:
      if ch == '*':
        a = int(st.pop())
        b = int(st.pop())
        st.append(str(a*b))
      elif ch == '/':
        b = int(st.pop())
        a = int(st.pop())
        st.append(str(int(a/b)))
      elif ch == '+':
        a = int(st.pop())
        b = int(st.pop())
        st.append(str(a+b))
      elif ch == '-':
        b = int(st.pop())
        a = int(st.pop())
        st.append(str(a-b))
      else:
        st.append(ch)
    return int(st.pop())