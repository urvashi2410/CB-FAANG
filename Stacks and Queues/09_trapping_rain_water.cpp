class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0){
            return 0;
        }
        
        vector<int>max_start(n);
        vector<int>max_end(n);
        
        max_start[0] = height[0];
        for(int i = 1; i < n; i++){
            max_start[i] = max(max_start[i-1], height[i]);
        }
        
        max_end[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            max_end[i] = max(max_end[i+1], height[i]);
        }
        
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            int level = min(max_start[i], max_end[i]);
            if(level-height[i] > 0){
                ans += (level - height[i]);
            }
        }
        return ans;
    }
};