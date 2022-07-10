// some problem in this 

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>>dp(n, vector<int>(m, 0));
        int ans = 0;
        
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(i == n-1 && j == m-1){
                    dp[i][j] = matrix[i][j] - '0';
                }
                else if(i == n-1){
                    dp[i][j] = matrix[i][j] - '0';
                }
                else if(j == m-1){
                    dp[i][j] = matrix[i][j] - '0';
                }
                else{
                    if(matrix[i][j] == '0'){
                        dp[i][j] = 0;
                    }
                    else{
                        int minimum = min(dp[i][j+1], dp[i+1][j]);
                        minimum = min(minimum, dp[i+1][j+1]);
                        dp[i][j] = minimum + 1;
                        if(ans < dp[i][j]){
                            ans = dp[i][j];
                        }
                    }
                }
            }
        }
        return ans*ans;
    }
};