class Solution {
public:
    int largestInteger(int num) {
      string n = to_string(num);
      priority_queue<char>opq;
      priority_queue<char>epq;
      for(char ch:n){
        if((ch - '0')%2)
          epq.push(ch);
        else
          opq.push(ch);
      }
      int ans = 0;
      for(char &ch:n){
        if((ch - '0')%2){
          ch = epq.top();
          epq.pop();
        }
        else{
          ch = opq.top();
          opq.pop();
        }
      }
      cout<<n;
      return stoi(n);
    }
};