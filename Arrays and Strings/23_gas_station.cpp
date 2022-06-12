class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int net = 0;
        int curr = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); i++){
            net += gas[i] - cost[i];
            curr += gas[i] - cost[i];
            
            if(curr < 0){
                curr = 0;
                start = i+1;
            }
        }
        if(net < 0){
            return -1;
        }
        return start;
    }
};