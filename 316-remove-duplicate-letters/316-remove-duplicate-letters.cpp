class Solution {
public:
    string removeDuplicateLetters(string s) {
      //use a stack
      //add first element from string to the stack
      //now loop through the second element from the string
      //if this element already exist in the stack, ignore and loop to the next element
      //while current element in string is less than top element from the stack and it exist in the later part of string, remove the top
      // now add this element in the stack
      stack<char> st;
      st.push(s[0]);
      unordered_map<char, bool>exist;
      unordered_map<char, int>freq;
      exist[s[0]] = true;
      for(int i=1; i<s.length(); i++)
        freq[s[i]]++; 
      for(int i=1; i<s.length(); i++){
        freq[s[i]]--;
        if(exist[s[i]])
          continue;
        char curr = s[i];
        while(!st.empty() and st.top() > curr and freq[st.top()] > 0){
          exist[st.top()] = false;
          st.pop();
        }
        st.push(curr);
        exist[curr] = true;
      }
      string res = "";
      while(!st.empty()){
        res = st.top() + res;
        st.pop();
      }
      return res;
    }
};