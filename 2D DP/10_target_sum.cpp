class Solution {
public:
    int minSum(vector<int> &nums){
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans = ans - nums[i];
        }
        return ans;
    }
    
    int maxSum(vector<int> &nums){
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans = ans + nums[i];
        }
        return ans;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int minsum = minSum(nums);
        int maxsum = maxSum(nums);
        
        if(target > maxsum || target < minsum){
            return 0;
        }
        
        int n = nums.size();
        int m = maxsum - minsum + 1;
        
        vector<vector<int>>dp(n, vector<int>(m, 0));
        
        // initialise first row 
        for(int i = 0; i < m; i++){
            bool op1 = (i+minsum) == nums[0];
            bool op2 = (i+minsum) == (-1)*nums[0];
            if(op1){
                dp[0][i] += 1;
            }
            if(op2){
                dp[0][i] += 1;
            }
        }
        
        // build the rest of the matrix 
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                int a1 = (j-nums[i] >= 0) ? dp[i-1][j-nums[i]] : 0;
                int a2 = (j+nums[i] < m) ? dp[i-1][j+nums[i]] : 0;
                dp[i][j] = a1 + a2;
            }
        }
        return dp[n-1][target-minsum];
    }
};