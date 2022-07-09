class Solution {
public:
    // It will exceed the time limit 
    // int countRecursion(int m, int n, int i, int j){
    //     if(i == m-1 && j == n-1){
    //         return 1;
    //     }

    //     if(i >= m || j >= n){
    //         return 0;
    //     }

    //     int rightPaths = countRecursion(m, n, i, j+1);
    //     int downPaths = countRecursion(m, n, i+1, j);

    //     return rightPaths + downPaths;
    // }

    // int countMemoization(int m, int n, int i, int j, vector<vector<int>>&dp){
    //     if(i == m-1 && j == n-1){
    //         return 1;
    //     }

    //     if(i >= m || j >= n){
    //         return 0;
    //     }

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     int rightPaths = countMemoization(m, n, i, j+1, dp);
    //     int downPaths = countMemoization(m, n, i+1, j, dp);
    //     dp[i][j] = rightPaths + downPaths;
    //     return rightPaths + downPaths;
    // }

    int countTabular(int m , int n){
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }

        for(int j = 0; j < n; j++){
            dp[0][j] = 1;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

    int uniquePaths(int m, int n) {
        // return countRecursion(m, n, 0, 0);
        // vector<vector<int>>dp(m, vector<int>(n, -1));
        // return countMemoization(m, n, 0, 0, dp);
        return countTabular(m, n);
    }
};