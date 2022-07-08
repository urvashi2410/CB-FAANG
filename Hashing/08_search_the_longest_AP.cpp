class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        
        unordered_map<int, list<int>>m;
        int ans = 2;
        
        for(int i = 0; i < n; i++){
            m[nums[i]].push_back(i);
        }
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int d = nums[j] - nums[i];
                int num = nums[j] + d;
                int count = 2;
                int pos = j;
                
                while(m.find(num) != m.end()){
                    bool flag = false;
                    for(auto node : m[num]){
                        if(node > pos){
                            count++;
                            num += d;
                            pos = node;
                            flag = true;
                            break;
                        }
                    }
                    if(flag == false){
                        break;
                    }
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};