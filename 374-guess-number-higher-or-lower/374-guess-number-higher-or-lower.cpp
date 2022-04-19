/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
      unsigned long int b = 1;
      unsigned long int e = n;
      unsigned long int m = (b + e)>>1;
     
      while (guess(m) != 0){
        if(guess(m) == 1)
          b = m+1;
        else if(guess(m) == -1)
          e = m-1;
        m = (b + e)>>1;
      }
      return m;
    }
};