#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string>ans;
        int i = 0;
        
        while(i < n){
            string temp = "";
            temp += to_string(nums[i]);
            int num = nums[i];
            
            while(i+1 < n && nums[i+1] == nums[i]+1){
                i++;
            }
            if(nums[i] != num){
                temp += "->";
                temp += to_string(nums[i]);
            }
            ans.push_back(temp);
            i++;
        }
        return ans;
    }
};