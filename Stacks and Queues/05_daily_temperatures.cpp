class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans;
        int n = temperatures.size();
        
        for(int i = 0; i < n; i++){
            ans.push_back(0);
        }
        stack<int>s;
        int i = 0;
        while(i < n){
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                int x = s.top();
                s.pop();
                ans[x] = i - x;
            }
            s.push(i);
            i++;
        }
        return ans;
    }
};