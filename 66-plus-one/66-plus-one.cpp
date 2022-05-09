class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      list<int>ans;
      int r = 1;
      int d = 0;
      int s = 0;
      for(auto it=digits.rbegin(); it<digits.rend(); it++){
        s = *it+r;
        d = s%10;
        if(s>9)
          r = 1; 
        else
          r = 0;
        ans.push_front(d);
      }
      if(r == 1)
        ans.push_front(1);
      
      return vector(ans.begin(), ans.end());;
        
    }
};