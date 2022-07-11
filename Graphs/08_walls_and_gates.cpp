#include <bits/stdc++.h>
using namespace std;

bool isvisited(int i, int j, int n, int m, vector<vector<bool>> &visited){
    if(i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == INT_MAX){
        return true;
    }
    return false;
}

void wallsAndGates(vector<vector<int>> &rooms){
    int n = rooms.size();
    if(n == 0){
        return;
    }

    queue<pair<int, int>>q;

    int m = rooms[0].size();
    vector<vector<bool>>visited(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(rooms[i][j] == 0){
                q.push(make_pair(i, j));
                visited[i][j] = true;
            }
        }

        while(!q.empty()){
            pair<int, int>p = q.front();
            q.pop();
            
            int x = p.first;
            int y = p.second;

            int dir[5] = {-1, 0, 1, 0, -1};

            for(int i = 0; i < 4; i++){
                int nx = x + dir[i];
                int ny = y + dir[i+1];

                if(isvisited(nx, ny, n, m,  visited)){
                    rooms[nx][ny] = rooms[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }   
}