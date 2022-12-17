class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<string>st;
      for(string ch:tokens){
         if(ch == "*"){
            long long a = stol(st.top());
            st.pop();
            long long b = stol(st.top());
            st.pop();
            st.push(to_string(a*b));
          }
          else if(ch ==  "/"){
            long long b = stol(st.top());
            st.pop();
            long long a = stol(st.top());
            st.pop();
            st.push(to_string(a/b));
          }
          else if(ch == "-"){
            long long b = stol(st.top());
            st.pop();
            long long a = stol(st.top());
            st.pop();
            st.push(to_string(a-b));
          }
          else if(ch == "+"){
            long long a = stol(st.top());
            st.pop();
            long long b = stol(st.top());
            st.pop();
            st.push(to_string(a+b));
          }
          else{
            st.push(ch);
          }
        }
        return stoi(st.top());
      }
};