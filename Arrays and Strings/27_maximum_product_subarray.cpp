// one case left 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        
        int pp = 1;
        int np = 1;
        int maxi = INT_MIN;
        bool hasZero = false, hasPos = false;
        
        for(int i : nums){
            if(i > 0){
                hasPos = true;
                pp *= i;
                if(np != 1){
                    np *= i;
                }
            }
            else if(i < 0){
                int temp = pp;
                pp = max(1, np*i);
                np = temp*i;
            }
            else if(i == 0){
                np = pp = 1;
                hasZero = true; 
            }
            if(maxi < pp){
                maxi = pp;
            }
        }
        if(maxi == 1){
            if(hasPos){
                return maxi;
            }
            if(hasZero){
                return 0;
            }
        }
        return maxi;
    }
};