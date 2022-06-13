// 1 
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int curr_sum = 0;
        int pos = 0;
        
        for(int i = 0; i < k; i++){
            curr_sum += abs(arr[i]-x);
        }
        int sum = curr_sum;
        for(int i = 1; i <= n-k; i++){
            curr_sum -= abs(arr[i-1]-x);
            curr_sum += abs(arr[i+k-1]-x);
            if(curr_sum < sum){
                sum = curr_sum;
                pos = i;
            }
        }
        vector<int>ans;
        for(int i = 0; i < k; i++){
            ans.push_back(arr[i+pos]);
        }
        return ans;
    }
};
// 2 
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int,int>>maxh;
        for(int i = 0; i < n; i++){
            maxh.push(make_pair(abs(arr[i] - x), arr[i]));
            
            if(maxh.size() > k){
                maxh.pop();
            }
        }
        
        vector<int>ans;
        while(!maxh.empty()){
            int top = maxh.top().second;
            maxh.pop();
            ans.push_back(top);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};