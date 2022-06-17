class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int low;
        int high;
        int start = 0;
        int maxLen = 1;
        
        // odd
        for(int i = 0; i < n; i++){
            low = i-1;
            high = i;
            while(low >= 0 && high < n && s[low] == s[high]){
                if((high-low+1) > maxLen){
                    start = low;
                    maxLen = high-low+1;
                }
                low--;
                high++;
            }
        }
        
        // even
        for(int i = 0; i < n; i++){
            low = i-1;
            high = i+1;
            while(low >= 0 && high < n && s[low] == s[high]){
                if((high-low+1) > maxLen){
                    start = low;
                    maxLen = high - low+1;
                }
                low--;
                high++;
            }
        }
        
        string res = "";
        for(int i = start; i < (start+maxLen); i++){
            res += s[i];
        }
        return res;
    }
};