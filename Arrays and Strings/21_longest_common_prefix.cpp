class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0){
            return "";
        }
        
        string ans = strs[0];
        for(int i = 1; i < n; i++){
            string temp = "";
            int minSizeToInterateIn = min(ans.size(), strs[i].size());
            for(int j = 0; j < minSizeToInterateIn; j++){
                if(ans[j] == strs[i][j]){
                    temp += ans[j];
                }
                else{
                    break;
                }
            }
            ans = temp;
        }
        return ans;
    }
};