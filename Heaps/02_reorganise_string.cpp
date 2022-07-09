class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int>m;
        for(int i = 0; i < s.size(); i++){
            m[s[i]]++;
        }
        
        priority_queue<pair<int, char>>p;
        for(auto i : m){
            p.push({i.second, i.first});
        }
        
        string ans = "";
        while(p.size() > 1){
            auto e1 = p.top();
            p.pop();
            auto e2 = p.top();
            p.pop();
            
            ans += e1.second;
            ans += e2.second;
            
            e1.first -= 1;
            e2.first -= 1;
            
            if(e1.first > 0){
                p.push(e1);
            }
            
            if(e2.first > 0){
                p.push(e2);
            }
        }
        
        if(!p.empty()){
            if(p.top().first > 1){
                return "";
            }
            else{
                ans += p.top().second;
                p.pop();
            }
        }
        return ans;
    }
};