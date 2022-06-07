// You have to make an array whose elements sum to 0 

#include <bits/stdc++.h>
using namespace std;

vector<int> targetZero(int n){
    vector<int>ans;
    int n1 = floor(n/2.0);
    for(int i = 0; i < n1; i++){
        ans.push_back(i);
        ans.push_back(-1*i);
    }
    if(n&1){
        ans.push_back(0);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int>ans = targetZero(n);
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}