class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        string temp = "";
        stack<pair<string, int>> st;
        int i = 0;
        int n = s.size();
        
        while(i < n){
            if(isdigit(s[i])){
                int num = 0;
                while(isdigit(s[i])){
                    int tempnum = s[i] - '0';
                    num = num*10 + tempnum;
                    i++;
                }
                st.push(make_pair(temp, num));
                temp = "";
            }
            else if(isalpha(s[i])){
                temp += s[i];
            }
            else if(s[i] == ']'){
                pair<string, int>p = st.top();
                st.pop();
                
                string curr = p.first;
                for(int i = 0; i < p.second; i++){
                    curr += temp;
                }
                if(s.empty()){
                    ans += curr;
                }
                else{
                    temp = curr;
                }
            }
            i++;
        }
        ans += temp;
        return ans;
    }
};