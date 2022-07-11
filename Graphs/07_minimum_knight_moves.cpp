class Solution{
    public:
        bool isvalid(int i, int j, int n, vector<vector<bool>>& visited){
            if(i >= 0 && i < n && j >= 0 && j < n && visited[i][j] == false){
                return true;
            }
            return false;
        }

        int minStepToReachTarget(vector<int>&knightPos, vector<int>&targetPos, int n){
            int tx = targetPos[0] - 1;
            int ty = targetPos[1] - 1;
            int x1 = knightPos[0] - 1;
            int y1 = knightPos[1] - 1;

            if(x1 == tx && y1 == ty){
                return 0;
            }

            vector<vector<bool>> visited(n, vector<bool>(n, false));
            queue<pair<int, int>>q;

            q.push(make_pair(x1, y1));
            visited[x1][y1] = true;

            int ans = 0;
            while(!q.empty()){
                int size = q.size();
                ans++;
                while(size--){
                    pair<int, int>p = q.front();
                    q.pop();

                    int x = p.first;
                    int y = p.second;

                    int dirX[8] = {1,1,-1,-1,2,-2,2,-2};
                    int dirY[8] = {2,-2,2,-2,1,1,-1,-1};

                    for(int i = 0; i < 8; i++){
                        int nx = x + dirX[i];
                        int ny = y + dirY[i];

                        if(nx == tx && ny == ty){
                            return ans;
                        }

                        if(isvalid(nx, ny, n, visited)){
                            visited[nx][ny] = true;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
            return ans;
        }
};