class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // indegree vector 
        vector<int>indegree(numCourses, 0);
        
        // make a graph 
        unordered_map<int, vector<int>> graph;
        int total_edges = prerequisites.size();
        
        for(int i = 0; i <total_edges; i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        // make a queue for storing the nodes or courses having zero indegree 
        queue<int>zeroIndegree;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                zeroIndegree.push(i);
            }
        }
        
        // total edges removed in topological sort
        int edges_removed = 0;
        while(!zeroIndegree.empty()){
            int course = zeroIndegree.front();
            zeroIndegree.pop();
            for(auto child : graph[course]){
                edges_removed++;
                indegree[child]--;
                if(indegree[child] == 0){
                    zeroIndegree.push(child);
                }
            }
        }
        
        if(edges_removed == total_edges){
            return true;
        }
        else{
            return false;
        }
    }
};