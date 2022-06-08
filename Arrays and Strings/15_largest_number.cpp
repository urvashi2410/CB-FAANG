bool comp(int a, int b){
        string s1 = to_string(a);
        string s2 = to_string(b);
        return s1+s2 > s2+s1;
}
class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        int flag = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                flag = 1;
                break;
            }
        }
        
        if(flag == 1){
            string s = "";
            for(int i = 0; i < n; i++){
                s += to_string(nums[i]);
            }
            return s;
        }
        else{
            return "0";
        }
    }
};