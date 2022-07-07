class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool>m;
        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) != m.end()){
                return true;
            }
            else{
                m[nums[i]] = true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set(nums.begin(), nums.end()).size();
    }
};