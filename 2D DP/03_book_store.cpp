// to find max profit to sell all the books from the book if to buy a particular book the cost is cost[i]*cost[left]*cost[right]

#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int bookStore(int *a, int left, int right){
    // base case 
    memset(dp, -1, sizeof(dp));
    if(right-left <= 1){
        return 0;
    }
    if(dp[left][right] != -1){
        return dp[left][right];
    }
    int ans = 0;
    for(int pivot = left+1; pivot < right; pivot++){
        ans = max(ans, a[left]*a[pivot]*a[right]+bookStore(a, left, pivot)+bookStore(a, pivot, right));
    }
    dp[left][right] = ans;
    return dp[left][right];
}

int main(){
    int n;
    cin >> n;
    int a[n+2];
    a[0] = a[n+1] = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    cout << bookStore(a,0, n+1);
    return 0;
}