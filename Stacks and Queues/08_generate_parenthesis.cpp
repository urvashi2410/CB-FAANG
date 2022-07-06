class Solution {
public:
    void generate(vector<string> &ans, string parenthesis, int open, int close, int len){
        if(parenthesis.size() == 2*len){
            ans.push_back(parenthesis);
            return;
        }
        if(close < open){
            generate(ans, parenthesis+')', open, close+1, len);
        }
        if(open < len){
            generate(ans, parenthesis+'(', open+1, close, len);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generate(ans, "", 0, 0, n);
        return ans;
    }
};