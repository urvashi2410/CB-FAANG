class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i = 0;
        int j = 0;
        int n = s.size();
        int ans = 0;
        
        while(i < n && j < n){
            if(st.find(s[j]) == st.end()){
                st.insert(s[j++]);
                ans = max(ans, j-i);
            }
            else{
                st.erase(s[i++]);
            }
        }
        return ans;
    }
};