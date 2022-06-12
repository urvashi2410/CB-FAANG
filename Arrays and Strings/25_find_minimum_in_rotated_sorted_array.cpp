class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        
        if(nums[0] <= nums[n-1]){
            return nums[0];
        }
        while(l <= r){
            int mid = l + (r-l)/2;
            if(mid-1 >= 0 && nums[mid] < nums[mid-1]){
                return nums[mid];
            }
            else if(nums[mid] > nums[n-1]){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return -1;
    }
};