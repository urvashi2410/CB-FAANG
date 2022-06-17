class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        int ans;
        int a1,a2,b1,b2,c1,c2,d1,d2;
        a1 = b1 = c1 = d1 = INT_MIN;
        a2 = b2 = c2 = d2 = INT_MAX;
        
        for(int i = 0; i < n; i++){
            if(a1 < arr1[i]+arr2[i]+i){
                a1 = arr1[i]+arr2[i]+i;
            }
            if(a2 > arr1[i]+arr2[i]+i){
                a2 = arr1[i]+arr2[i]+i;
            }
            if(b1 < arr2[i]-arr1[i]+i){
                b1 = arr2[i]-arr1[i]+i;
            }
            if(b2 > arr2[i]-arr1[i]+i){
                b2 = arr2[i]-arr1[i]+i;
            }
            if(c1 < arr1[i]+arr2[i]-i){
                c1 = arr1[i]+arr2[i]-i;
            }
            if(c2 > arr1[i]+arr2[i]-i){
                c2 = arr1[i]+arr2[i]-i;
            }
            if(d1 < arr2[i]-arr1[i]-i){
                d1 = arr2[i]-arr1[i]-i;
            }
            if(d2 > arr2[i]-arr1[i]-i){
                d2 = arr2[i]-arr1[i]-i;
            }
        }
        int case1 = max(a1-a2, b1-b2);
        int case2 = max(c1-c2, d1-d2);
        ans = max(case1, case2);
        return ans;
    }
};