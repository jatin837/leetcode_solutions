class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sum = 0;
        int n = numbers.size();
        int start = 0;
        int end = n-1;
        vector<int> ans(2);
        while(start<=end){
            if(numbers[start]+numbers[end] == target){
                ans[0] = start+1;
                ans[1] = end+1;
                break;
            }
            if(numbers[start]+numbers[end] > target){
                end--;
            }else{
                start++;
            }
        }
        return ans;
    
    }
};