class Solution:
  def pushDominoes(self, dominoes: str) -> str:
    q = []
    for i, ch in enumerate(dominoes):
      if(ch == 'L' or ch == 'R'):
        q.append(i)
    while(len(q)):
      tmp = list(dominoes)
      sz = len(q)
      for _ in range(sz):
        top = q.pop(0)
        if(top-1>=0 and dominoes[top-1] == '.' and dominoes[top] == 'L'):
          if((top-2 >= 0 and dominoes[top-2] != 'R') or top-1 == 0):
            tmp[top-1] = 'L'
            q.append(top-1)
        elif(top+1<len(dominoes) and dominoes[top+1] == '.' and dominoes[top] == 'R'):
          if((top+1 == len(dominoes)-1) or (top+2 < len(dominoes) and dominoes[top+2] != 'L')):
            tmp[top+1] = 'R'
            q.append(top+1);
      dominoes = ''.join(tmp)
    return dominoes;