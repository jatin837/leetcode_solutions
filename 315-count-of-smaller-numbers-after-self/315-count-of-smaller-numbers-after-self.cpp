class Solution {
private:
    void merge_sort(int start, int end, vector<pair<int, int>>& nums, vector<int>& indices, vector<pair<int, int>>& temp) {
        if(start >= end)
            return;
        
        int mid = (start+end)>>1;
        
        merge_sort(start, mid, nums, indices, temp);
        merge_sort(mid+1, end, nums, indices, temp);
        
        int l=start, r=mid+1;
        int idx = start;
        int nRightLessThanLeft = 0;
        while(l <= mid and r <= end) {
            if(nums[l] < nums[r]) {
                indices[nums[l].second] += nRightLessThanLeft;
                temp[idx++] = nums[l++];
            } else if(nums[l] > nums[r]) {
                temp[idx++] = nums[r++];
                nRightLessThanLeft++;
            } else
                l++, r++;
        }
        
        while(l <= mid) {
            indices[nums[l].second] += nRightLessThanLeft;
            temp[idx++] = nums[l++];
        }
        
        while(r <= end)
            temp[idx++] = nums[r++];
        
        for(int i=start; i<=end; i++)
            nums[i] = temp[i];
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> new_nums; // {num, original_idx}
        vector<int> indices(n, 0);
        vector<pair<int, int>> temp;
        
        for(int i=0; i<n; i++) {
            new_nums.push_back({nums[i], i});
            temp.push_back({nums[i], i});
        }
        
        merge_sort(0, n-1, new_nums, indices, temp);
        
        return indices;
    }
};