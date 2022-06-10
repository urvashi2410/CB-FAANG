class Solution {
public:
    int find(vector<int>& arr, int n){
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == n){
                return i;
            }
        }
        return -1;
    }
    
    void flip(vector<int>& arr, int k){
        for(int i = 0; i < k/2; i++){
            int temp = arr[i];
            arr[i] = arr[k-i-1];
            arr[k-i-1] = temp;
        }
    }
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int>ans;
        int n = arr.size();
        while(n > 0){
            int idx = find(arr, n);
            if(idx != n-1){
                flip(arr, idx+1);
                flip(arr, n);
                ans.push_back(idx+1);
                ans.push_back(n);
            }
            n--;
        }
        return ans;
    }
}; 