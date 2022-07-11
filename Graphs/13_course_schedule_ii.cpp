class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // making a graph so that non-dependent courses have directed edges towards dependent courses 
        vector<vector<int>> adj(numCourses);
        
        // to store number of courses on which a course depends 
        vector<int>indegree(numCourses, 0);
        
        for(auto i : prerequisites){
            int u = i[1];
            int v = i[0];
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int>q;
        for(int i = 0; i < indegree.size(); i++){
            // pushing all the non dependent nodes in the queue because topological sort starts with the node with indegree 0 
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int>ans;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            
            ans.push_back(f);
            for(auto child : adj[f]){
                // after buying a particular course we reduce indegree of the courses which were dependent on it so that they are dependent on 1 less course now
                indegree[child]--;
                if(indegree[child] == 0){
                    q.push(child);
                }
            }
        }
        
        if(ans.size() == numCourses){
            return ans;
        }
        return {};
    }
};