//#define ll long long
//class Solution {
//public:
//    ll minSumSquareDiff(vector<int>& n1, vector<int>& n2, int k1, int k2) {
//      unordered_map<ll, ll>mp;
//      ll nops = 0;
//      ll sum = 0;
//      for(int i=0; i<n1.size(); i++)
//        mp[abs(n1[i] - n2[i])]++;
//      ll top = 0;
//      for(auto it=mp.begin(); it!=mp.end(); it++)
//        top = max(top, it->first);
//      while(nops < k1+k2 and top > 0){
//        if(mp[top]){
//          ll currOps = (mp[top] + nops <= k1+k2)?mp[top]:(k1+k2)-nops;
//          mp[top] -= currOps;
//          mp[top-1] += currOps;
//          nops += currOps;         
//        }
//        top--;
//      }
//      for(auto [x, y]:mp)
//        sum += x*x*y;
//      return sum;
//    }
//};


class Solution {
public:
    #define ll long long
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        unordered_map<ll, ll> mp;
        for(int i = 0; i < n; ++i) {
            mp[abs(nums1[i] - nums2[i])]++;
        }
        long long tot = k1 + k2;
        
        priority_queue<array<ll, 2>> pq;
        for(auto [x, y]: mp) {
            if(x == 0) continue;
            pq.push({x, y});
        }
        
        while(!pq.empty() and tot > 0) {
            array<ll, 2> v = pq.top();
            pq.pop();
            
            if(pq.size() == 0) {
                ll mn = min(tot, v[1]);    
                tot -= mn;
                v[1] -= mn;
                if(v[0] - 1 > 0) pq.push({v[0] - 1, mn});
                if(v[1] > 0) pq.push(v);
            } else {
                ll mn = min(tot, v[1]);
                tot -= mn;
                v[1] -= mn;
                if(v[1] > 0) pq.push(v);
                
                if(pq.top()[0] == v[0] - 1) {
                    array<ll, 2> v1 = pq.top();
                    pq.pop();
                    v1[1] += mn;
                    pq.push(v1);
                } else if(v[0] - 1 > 0) {
                    pq.push({v[0] - 1, mn});
                }
            }
        }
        
        ll ans = 0;
        while(!pq.empty()) {
            array<ll, 2> v = pq.top();
            ans += v[0] * v[0] * v[1];
            pq.pop();
        }
        return ans;
    }
};