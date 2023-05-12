//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        int ret = 0;
        int i=0;
        while(i < n and arr[i] == 0)
            i++;
        while(i < n){
            while(i < n and arr[i] != 0)
                i++;
            ret++;
            while(i < n and arr[i] == 0)
                i++;
        }
        if(ret == 1 and arr[0]*arr[n-1] != 0)
            return -1;
        return ret;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends