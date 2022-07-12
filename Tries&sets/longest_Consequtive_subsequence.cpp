class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        unordered_set<int>s(nums.begin(), nums.end());
        int ans = 1;
        for(int i : nums){
            // if a particular number is not in set means we already calculated longest consecutive subsequence including it 
            if(s.find(i) == s.end()){
                continue;
            }
            s.erase(i);
            
            int prev = i-1;
            int next = i+1;
            
            while(s.find(prev) != s.end()){
                s.erase(prev--);
            }
            while(s.find(next) != s.end()){
                s.erase(next++);
            }
            ans = max(ans, next-prev-1);
        }
        return ans;
    }
};