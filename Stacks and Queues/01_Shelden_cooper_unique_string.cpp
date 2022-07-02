#include <iostream>
#include <stack>
using namespace std;

int main(){
    char a[1000001];
    cin >> a;

    int lastIndex[26] = {0};
    bool presentInStack[26] = {0};

    for(int i = 0; a[i] != '\0'; i++){
        char ch = a[i];
        lastIndex[ch-'a'] = i;
    }

    stack<int>s;

    for(int i = 0; a[i] != '\0'; i++){
        char ch = a[i];
        if(!presentInStack[ch-'a']){
            while(!s.empty() && ch < s.top() && lastIndex[s.top()-'a'] > i){
                presentInStack[s.top()-'a'] = 0;
                s.pop();
            }

            s.push(ch);
            presentInStack[ch-'a'] = 1;
        }
    }

    int k = s.size();
    char *ans = new char[k+1];
    a[k--] = '\0';

    while(!s.empty()){
        ans[k] = s.top();
        s.pop();
        k--;
    }

    cout << ans << endl;
}