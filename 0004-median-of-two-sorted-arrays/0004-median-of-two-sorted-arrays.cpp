class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    
    // I need size(nums1) <= size(nums2)
    // if that is not the case, them swap nums1 to nums2
      
    if(m > n){
        return findMedianSortedArrays(nums2, nums1);
    }
    //conditional swap code ends
    
    int nlp = (m+n)>>1; // nlp -> Number of elements in left partition of merged array
    
    int s = 0;
    int e = m-1;
    
    int Ali;
    int Ari;
    int Bli;
    int Bri;
      
    int Aleft, Aright, Bleft, Bright;   
    
    while(true){
      int mid = (s+e)>>1; // mid position in nums1 array
      int x = nlp - (mid + 1) - 1; // mid position in nums2 array
      
      Ali = mid;
      Ari = mid + 1;
      Bli = x;
      Bri = x+1;
      

      if(Ali >= 0)
        Aleft = nums1[Ali];
      else
        Aleft = INT_MIN;
      
      if(Ari < nums1.size())
        Aright = nums1[Ari];
      else
        Aright = INT_MAX;
      
      if(Bli >= 0)
        Bleft = nums2[Bli];
      else
        Bleft = INT_MIN;
      
      if(Bri < nums2.size())
        Bright = nums2[Bri];
      else
        Bright = INT_MAX;
      
      if (Aleft <= Bright and Bleft <= Aright){
        if ((m+n)&1)
          return min(Aright, Bright);
        double a = max(Aleft, Bleft);
        double b = min(Aright, Bright);
        //cout<<Aleft<<' '<<Aright<<'\n';
        //cout<<Bleft<<' '<<Bright<<'\n';
        double ans = (a + b)/2;
        return ans; 
      }else if(Aleft > Bright)
        e = mid-1;
      else
        s = mid+1;
    }
  }
};