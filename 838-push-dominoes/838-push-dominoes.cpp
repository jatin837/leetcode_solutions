class Solution {
public:
  string pushDominoes(string dominoes) {
    queue<int> q;
    for(int i=0;i<dominoes.size();i++)
      if(dominoes[i]=='L' || dominoes[i]=='R')
        q.push(i);
    string ans = dominoes;
    while(!q.empty()){
      int s = q.size();
      for(int i=0;i<s;i++){
        auto p = q.front();
        q.pop();
        if(p-1>=0 && dominoes[p]=='L' && dominoes[p-1]=='.'){
          if(p-2>=0 && dominoes[p-2]!='R'){
            ans[p-1] = 'L';
            q.push(p-1);    
          }
          if(p-2<0)
            ans[p-1] = 'L';
        }
        if(p+1<dominoes.size() && dominoes[p]=='R' && dominoes[p+1]=='.'){
          if(p+2<dominoes.size() && (dominoes[p+2]!='L')) {
            ans[p+1] = 'R';
            q.push(p+1);
          }         
          if(p+2>=dominoes.size()){
            ans[p+1] = 'R';
          }
        }
      }
      dominoes = ans;
    }
  return dominoes;
}
};