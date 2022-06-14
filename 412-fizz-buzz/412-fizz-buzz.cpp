class Solution {
public:
    vector<string> fizzBuzz(int n) {
      vector<string>ans(n);
      for(int i=0; i<n; i++){
        int num = i+1;
        string res = "";
        if(num%3==0 or num%5==0){
          if(num%3==0)
            res+="Fizz";
          if(num%5==0)
            res+="Buzz";  
        }
        else
          res+=to_string(num);
        ans[i]=res;
      }
      return ans;
    }
};