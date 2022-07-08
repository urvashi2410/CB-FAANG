#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubkDistinct(string s, int k){
    int n = s.size();
    if(n*k == 0){
        return 0;
    }

    int left = 0;
    int maxlen = 0;
    unordered_map<char, int>m;

    for(int right = 0; right < n; right++){
        char ch = s[right];
        m[ch] = right;
        if(m.size() == k+1){
            char minCharIndex = '0';
            int minIndx = INT_MAX;
            for(auto i : m){
                if(i.second < minIndx){
                    minCharIndex = i.first;
                    minIndx = i.second;
                }
            }
            left = minIndx + 1;
            m.erase(minCharIndex);
        }
        maxlen = max(maxlen, right-left+1);
    }
    return maxlen;
}

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << lengthOfLongestSubkDistinct(s, k);
}