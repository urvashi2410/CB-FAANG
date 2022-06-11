class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        int left = 0;
        int right = n-1;
        
        while(curr <= right){
            if(nums[curr] == 0){
                swap(nums[curr], nums[left]);
                left++;
                curr++;
            }
            else if(nums[curr] == 2){
                swap(nums[curr], nums[right]);
                right--;
            }
            else{
                curr++;
            }
        }
    }
};