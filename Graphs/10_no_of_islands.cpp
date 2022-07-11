class Solution {
public:
    bool isvalid(vector<vector<char>> &grid, int n, int m, int i, int j){
        if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1'){
            return true;
        }
        return false;
    }
    
    void explore(vector<vector<char>> &grid, int n, int m , int i, int j){
        // means it is visited 
        grid[i][j] = '0';
        
        if(isvalid(grid, n, m, i+1, j)){
            explore(grid, n, m, i+1, j);
        }
        if(isvalid(grid, n, m, i-1, j)){
            explore(grid, n, m, i-1, j);
        }
        if(isvalid(grid, n, m, i, j+1)){
            explore(grid, n, m, i, j+1);
        }
        if(isvalid(grid, n, m, i, j-1)){
            explore(grid, n, m, i, j-1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    count++;
                    explore(grid, n, m, i, j);
                }
            }
        }
        return count;
    }
};