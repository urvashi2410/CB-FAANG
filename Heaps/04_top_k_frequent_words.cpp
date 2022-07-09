class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        unordered_map<string, int>m;
        for(auto i : words){
            m[i]++;
        }
        
        // max heap
        priority_queue<pair<int, string>>p;
    
        for(auto i : m){
            p.push(make_pair(-i.second, i.first));
            if(p.size() > k){
                p.pop();
            }
        }
        
        while(k--){
            ans.push_back(p.top().second);
            p.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};