class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
      sort(begin(people), end(people));
      int i=0, j=people.size()-1;
      int cnt=0;
      while(i<=j){
        cnt++;
        if(people[i] + people[j] <= limit)
          i++;
        j--;
      }
      return cnt;
    }
};