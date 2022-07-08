// solution 1 - TC - O(nlogk)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>>minh;
        for(auto &i : mp){
            minh.push(make_pair(i.second, i.first));
            if(minh.size() > k){
                minh.pop();
            }
        }
        
        vector<int>ans;
        while(!minh.empty()){
            int top = minh.top().second;
            minh.pop();
            ans.push_back(top);
        }
        return ans;
    }
};

// Solution-2 TC - O(n) - bucket sort 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>freq;
        for(int i : nums){
            freq[i]++;
        }
        
        int n = nums.size();
        vector<vector<int>> bucket(n, vector<int>());
        for(auto i : freq){
            bucket[i.second-1].push_back(i.first);
        }
        
        vector<int>topK;
        for(int i = bucket.size()-1; i >= 0 && k > 0; i--){
            for(int val : bucket[i]){
                topK.push_back(val);
                k--;
            }
        }
        return topK;
    }
};