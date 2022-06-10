class Solution {
public:
    bool single(vector<int> &nums, int mid){
        int n = nums.size();
        if(mid == 0 && nums[0]!=nums[1]){
            return true;
        }
        if(mid == n-1 && nums[mid-1]!=nums[mid]){
            return true;
        }
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
            return true;
        }
        return false;
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        int start = 0;
        int end = n-1;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            if(single(nums, mid)){
                return nums[mid];
            }
            if(mid + 1 < n && nums[mid] == nums[mid+1]){
                if(mid%2 == 0){
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
            if(mid - 1 >= 0 && nums[mid] == nums[mid-1]){
                if((mid-1) % 2 == 0){
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
        } 
        return nums[start];
    }
};