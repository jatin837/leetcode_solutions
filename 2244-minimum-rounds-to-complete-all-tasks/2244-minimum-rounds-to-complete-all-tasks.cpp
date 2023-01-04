class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
      int round = 0;
      sort(tasks.begin(), tasks.end());
      int p1=0;
      int p2=0;
      while(p1<tasks.size() && p2<tasks.size()){
        while(p2 < tasks.size() && tasks[p1] == tasks[p2])
          p2++;
        if(p2-p1 < 2)
          return -1;
        int q = (p2-p1)/3;
        int r = (p2-p1)%3;
        round += q + int(r != 0);
        p1=p2;
      }
      return round;
    }
};