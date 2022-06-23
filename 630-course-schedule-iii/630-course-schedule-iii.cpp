class Solution {
public:
    static bool cmp(vector<int> &l, vector<int> &r){
      return l[1] < r[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
      sort(begin(courses), end(courses), cmp);
      int time = 0;
      int count = 0;
      for(int i=0; i<courses.size(); i++){
        if(time+courses[i][0] <= courses[i][1]){
          time += courses[i][0];
          courses[count++] = courses[i];
        }else{
          int max_i = i;
          for(int j=0; j<count; j++)
            if(courses[j][0] > courses[max_i][0])
              max_i = j;
          if(courses[max_i][0] > courses[i][0]){
            time += courses[i][0] - courses[max_i][0];
            courses[max_i] = courses[i];
          }
        }
      }
      return count;
    }
};