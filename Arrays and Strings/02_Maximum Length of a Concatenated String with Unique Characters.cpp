class Solution {
public:
    int helper(vector<string>& arr, int i, string s){
        if(i == arr.size()){
            if(s.size()>26){
                return 0;
            }
            
            int freq[26] = {0};
            for(int k = 0; k < s.size(); k++){
                // if already present in freq array means its repeating 
                if(freq[s[k] - 'a'] == 1) {
                    return 0;
                }
                freq[s[k] - 'a']++;
            }
            return s.size();
        }
        
        int op1, op2;
        op1 = op2 = INT_MIN;
        if(s.size() + arr[i].size() <= 26){
            op1 = helper(arr, i+1, s+arr[i]);
        }
        op2 = helper(arr, i+1, s);
        return max(op1, op2);
    }
    
    int maxLength(vector<string>& arr) {
        return helper(arr, 0, "");
    }
};