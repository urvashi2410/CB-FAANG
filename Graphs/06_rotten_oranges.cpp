class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dir = {-1, 0, 1, 0, -1};
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        int fresh = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        int ans = -1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int, int>p = q.front();
                q.pop();
                
                for(int i = 0; i < 4; i++){
                    int x = p.first + dir[i];
                    int y = p.second + dir[i+1];
                    
                    if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x,y});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        
        if(fresh > 0){
            return -1;
        }
        if(ans == -1){
            return 0;
        }
        return ans;
    }
};