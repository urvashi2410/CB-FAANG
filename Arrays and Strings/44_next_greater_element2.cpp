class Solution {
public:
    int nextGreaterElement(int num) {
        string s = to_string(num);
        int n = s.size();
        int i = n-2;
        
        while(i >= 0){
            if(s[i] < s[i+1]){
                break;
            }
            i--;
        }
        
        if(i < 0){
            return -1;
        }
        
        int j = n-1;
        while(j >= 0){
            if(s[i] < s[j]){
                break;
            }
            j--;
        }
        
        swap(s[i], s[j]);
        reverse(s.begin()+i+1, s.end());
        long long res = stol(s);
        
        if(res > INT_MAX || res < INT_MIN){
            return -1;
        }
        return res;
    }
};