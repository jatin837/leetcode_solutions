+ after sorting
```
people = {
[7,0],
[7,1],
[6,1],
[5,0],
[5,2],
[4,4]
}
```
+ insertions
```
ans = {}
ans = {[7,0]}
ans = {[7,0],[7,1]}
ans = {[7,0],[6,1],[7,1]}
ans = {[5,0],[7,0],[6,1],[7,1]}
ans = {[5,0],[7,0],[5,2],[6,1],[7,1]}
ans = {[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]}
```
​
## Code
```cpp
class Solution {
public:
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
vector<vector<int>> ans;
​
sort(begin(people), end(people), [](const vector<int>& a, const vector<int>& b) {
return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
});
for (auto p:people)
ans.insert(begin(ans) + p[1], p);
​
return ans;
}
};
```
​
## Analysis
```
Time Complexity
sorting + insertions = O(N*logN + N)
​
Space Complexity
auxiliary space required = O(N)
```
​