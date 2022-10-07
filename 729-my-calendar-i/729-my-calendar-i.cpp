class MyCalendar {
  map<int, int> diff;
public:
    bool book(int s, int e) {
      diff[s]++;diff[e]--;
      int curr = 0;
      for(auto [t, cnt]:diff){
        if(curr+cnt >= 2){
          diff[s]--;
          diff[e]++;
          return false;
        }
        curr += cnt;
      }
      return true;
    }
};

/**
* Your MyCalendar object will be instantiated and called as such:
* MyCalendar* obj = new MyCalendar();
* bool param_1 = obj->book(start,end);
*/