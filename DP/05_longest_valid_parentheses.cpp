// to find continuous valid parentheses length 

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int ans = 0;
        int cur = 0;
        int i = 0;
        
        while(i < s.size()){
            if(s[i] == '('){
                st.push(cur);
                cur = 0;
            }
            else{
                if(st.empty()){
                    cur = 0;
                }
                else{
                    cur = cur + st.top() + 2;
                    st.pop();
                    ans = max(ans, cur);
                }
            }
            i++;
        }
        return ans;
    }
};