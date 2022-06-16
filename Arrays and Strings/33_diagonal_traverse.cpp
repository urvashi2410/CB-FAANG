#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.size() == 0){
            vector<int>base;
            return base;
        }
        
        int n = mat.size();
        int m = mat[0].size();
        int row = 0;
        int col = 0;
        int dir = 1;
        
        vector<int>ans(n*m);
        for(int i = 0; i < ans.size(); i++){
            ans[i] = mat[row][col];
            if(dir == 1){
                if(col == m-1){
                    row++;
                    dir = -1;
                }
                else if(row == 0){
                    col++;
                    dir = -1;
                }
                else{
                    row--;
                    col++;
                }
            }
            else{
                if(row == n-1){
                    col++;
                    dir = 1;
                }
                else if(col == 0){
                    row++;
                    dir = 1;
                }
                else{
                    row++;
                    col--;
                }
            }
        }
        return ans;
    }
};