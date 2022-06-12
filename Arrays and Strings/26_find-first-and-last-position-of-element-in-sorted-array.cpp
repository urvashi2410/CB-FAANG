class Solution {
public:
    int first_index(vector<int>& nums, int target){
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int a = INT_MAX;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                a = min(a, mid);
                r = mid - 1;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        
        if(a == INT_MAX){
            return -1;
        }
        return a;
    }
    
    int last_index(vector<int>& nums, int target){
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int b = INT_MIN;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                b = max(b, mid);
                l = mid + 1;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        if(b == INT_MIN){
            return -1;
        }
        return b;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int ans1 = first_index(nums, target);
        int ans2 = last_index(nums, target);
        vector<int>ans;
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};