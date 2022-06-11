class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>m;
        m[0] = -1;
        int sum = 0;
        int ans;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                sum++;
            }
            else{
                sum--;
            }
            if(m.find(sum) != m.end()){
                ans = max(ans, i - m[sum]);
            }
            else{
                m[sum] = i;
            }
        }
        return ans;
    }
};