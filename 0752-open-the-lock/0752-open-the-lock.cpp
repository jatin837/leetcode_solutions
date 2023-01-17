class Solution {
public:
    vector<string>next(string& curr){
      vector<string>ret;
      for(int i=0; i<curr.length(); i++){
        string tmp = curr;
        int dig = tmp[i] - '0';
        tmp[i] = '0' + (dig+1)%10;
        ret.push_back(tmp);
        tmp[i] = '0' + (10+(dig-1)%10)%10;
        ret.push_back(tmp);
      }
      return ret;
    }
    int openLock(vector<string>& deadends, string target) {
      string curr = "0000";
      unordered_set<string>visited(deadends.begin(), deadends.end());
      if(visited.count(curr))
        return -1;
      queue<pair<string, int>>q;
      visited.insert(curr);
      q.push({curr, 0});
      while(q.size()){
        auto [cur, dist] = q.front();
        q.pop();
        if(cur == target)
          return dist;
        for(string n:next(cur)){
          if(visited.count(n))
            continue;
          q.push({n, dist+1});
          visited.insert(n);
        }
      }
      return -1;
    }
};