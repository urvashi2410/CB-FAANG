class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        // to convert empty string 1 into any of the string 2 we need insertions equal to the length of string 2 
        for(int i = 1; i <= n; i++){
            dp[i][0] = i;
        }
        
        // to convert any of the string 1 into empty string 2 we need deletions equal to the length of string 2 
        for(int j = 1; j <= m; j++){
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    // taking minimum of three type of operations(update, insert, delete)
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        return dp[n][m];
    }
};