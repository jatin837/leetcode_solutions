class MyCalendarTwo {
public:
    map<int, int>diff;
    MyCalendarTwo() {}
    bool book(int start, int end) {
      diff[start]++;
      diff[end]--;
      int curr = 0;
      for(auto [t, cnt]:diff)
        if(curr + cnt >= 3){
          diff[start]--;
          diff[end]++;
          return false;
        }
        else
          curr += cnt;
      return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */