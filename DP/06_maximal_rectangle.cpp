class Solution {
public:
    vector<int> NSL(vector<int>& heights){
        int n = heights.size();
        vector<int>ans;
        stack<pair<int, int>>s;
        
        for(int i = 0; i < n; i++){
            if(s.empty()){
                ans.push_back(-1);
            }
            else if(!s.empty() && s.top().first < heights[i]){
                ans.push_back(s.top().second);
            }
            else if(!s.empty() && s.top().first >= heights[i]){
                while(!s.empty() && s.top().first >= heights[i]){
                    s.pop();
                }
                if(s.empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(s.top().second);
                }
            }
            s.push({heights[i], i});
        }
        return ans;
    }
    
    vector<int> NSR(vector<int>& heights){
        int n = heights.size();
        vector<int>ans;
        stack<pair<int, int>>s;
        
        for(int i = n-1; i >= 0; i--){
            if(s.empty()){
                ans.push_back(n);
            }
            else if(!s.empty() && s.top().first < heights[i]){
                ans.push_back(s.top().second);
            }
            else if(!s.empty() && s.top().first >= heights[i]){
                while(!s.empty() && s.top().first >= heights[i]){
                    s.pop();
                }
                if(s.empty()){
                    ans.push_back(n);
                }
                else{
                    ans.push_back(s.top().second);
                }
            }
            s.push({heights[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>start = NSL(heights);
        vector<int>end = NSR(heights);
        vector<int>areas(n);
        
        for(int i = 0; i < n; i++){
            areas[i] = (end[i] - start[i] - 1)*heights[i];
        }
        
        int maxRectArea = INT_MIN;
        for(auto i : areas){
            maxRectArea = max(maxRectArea, i);
        }
        return maxRectArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        
        if(n == 0){
            return 0;
        }
        
        int m = matrix[0].size();
        vector<int>heights;
        
        for(int j = 0; j < m; j++){
            heights.push_back(matrix[0][j] - '0');
        }
        
        int maximumRect = largestRectangleArea(heights);
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '0'){
                    heights[j] = 0;
                }
                else{
                    heights[j] = heights[j] + (matrix[i][j] - '0');
                }
            }
            maximumRect = max(maximumRect, largestRectangleArea(heights));
        } 
        return maximumRect;
    }
};