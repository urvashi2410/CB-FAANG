#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    int maxHeight = INT_MIN;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num >= maxHeight){
            ans++;
            maxHeight = num;
        }
    }
    cout << ans << endl;
    return 0;
}