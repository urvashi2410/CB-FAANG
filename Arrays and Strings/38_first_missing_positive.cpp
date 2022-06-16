#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] <= 0 || nums[i] > n+1){
                nums[i] = n+2;
            }
        }
        
        for(int num: nums){
            int i = num > 0? num-1: -num-1;
            if(i >= 0 && i < n){
                nums[i] = -abs(nums[i]);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                return i+1;
            }
        }
        return n+1;
    }
};