class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long int>psum(n+1);
        long long int x = 0;
        for(int i = 0; i < n; i++){
            x += nums[i];
            psum[i] = x;
        }
        deque<pair<long long int,int>>q;
        q.push_back({0, -1});
        
        int ans = INT_MAX;
        
        for(int i = 0; i < n; i++){
            while(!q.empty() && psum[i]-q.front().first >= k){
                // we need to calculate the answer 
                ans = min(ans, (i-q.front().second));
                q.pop_front();  
            }
            while(!q.empty() && psum[i] <= q.back().first){
                q.pop_back();
            }
            q.push_back({psum[i], i});
        }
        if(ans == INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};