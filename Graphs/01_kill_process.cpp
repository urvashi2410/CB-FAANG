// Q.if processes have their parent processes then tell the number of processes that should be killed to kill a particular process 
vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill){
    unordered_map<int, vector<int>>m;
    vector<int>v;

    for(int i = 0; i < pid.size(); i++){
        m[ppid[i]].push_back(pid[i]);
    }
    
    // applying bfs 
    queue<int>q;
    q.push(kill);
    v.push_back(kill);

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int child : m[temp]){
            v.push_back(child);
            q.push(child);
        }
    }
    return v;
}