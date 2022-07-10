class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>dp(amount+1);
        
        // to get total of 0 amount there is one way to not to give any coin 
        dp[0] = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = coins[i]; j < amount+1; j++){
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};