class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // step 1: store all indexes having 0
        vector<int>zeroes;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 0){
                zeroes.push_back(i);
            }
        }
        
        // step 2: building the adjacency list 
        unordered_map<int, vector<int>>m;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 0){
                continue;
            }
            else{
                if(i+arr[i] < arr.size()){
                    m[i].push_back(i + arr[i]);
                }
                if(i - arr[i] >= 0){
                    m[i].push_back(i - arr[i]);
                }
            }
        }
        
        // step 3: bfs 
        unordered_map<int, bool>visited;
        
        for(int i = 0; i < arr.size(); i++){
            visited[i] = false;
        }
        
        queue<int>q;
        q.push(start);
        visited[start] = true;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(auto child : m[f]){
                if(!visited[child]){
                    q.push(child);
                    visited[child] = true;
                }
            }
        }
        
        // 4. checking 
        for(int i = 0; i < zeroes.size(); i++){
            if(visited[zeroes[i]]){
                return true;
            }
        }
        return false;
    }
};