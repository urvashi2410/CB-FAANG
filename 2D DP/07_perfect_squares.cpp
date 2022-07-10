class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1);
        
        // to make 0 we cannot use square of any number
        dp[0] = 0;
        
        // to make 1 we can only use 1^2 
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            int minimum = INT_MAX;
            for(int j = 1; j*j <= i; j++){
                int rem = i - j*j;
                minimum = min(minimum, dp[rem]);
            }
            dp[i] = minimum + 1;
        }
        return dp[n];
    }
};