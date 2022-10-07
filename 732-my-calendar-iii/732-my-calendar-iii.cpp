class MyCalendarThree {
public:
    map<int, int>diff;
    int book(int start, int end) {
      this->diff[start]++;
      this->diff[end]--;
      int ret = 0;
      int curr = 0;
      for(auto [x, y]:diff){
        curr += y;
        ret = max(ret, curr);
      }
      return ret;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */