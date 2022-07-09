class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>>maxh;
        int size = points.size();
        for(int i = 0; i < size; i++){
            int x = points[i][0];
            int y = points[i][1];
            int dis = x*x + y*y;
            maxh.push({dis, {x,y}});
            if(maxh.size() > k){
                maxh.pop();
            }
        }
        vector<vector<int>>ans;
        while(!maxh.empty()){
            pair<int,int>p = maxh.top().second;
            int x = p.first;
            int y = p.second;
            ans.push_back({x,y});
            maxh.pop();
        }
        return ans;
    }
};