class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
      int five=0;
      int ten=0;
      for(int bill:bills){
        int change = bill-5;
        if(change == 0){
          five++;
        }else if(change == 5){
          if(five==0)
            return false;
          ten++;
          five--;
        }else{
          if(five >=1 and ten >= 1){
            five--;
            ten--;
          }else if(five >= 3){
            five-=3;
          }else
            return false;
        }
      }
      return true;
    }
};