#include <bits/stdc++.h>
using namespace std;

int min_distance(vector<string>& words, string word1, string word2){
    int minDis = words.size();
    if(word1 == word2){
        int p = -1;
        for(int i = 0; i < words.size(); i++){
            if(words[i] == word1){
                if(p == -1){
                    p = i;
                }
                else{
                    minDis = min(minDis, abs(i - p));
                    p = i;
                }
            }
        }
    }
    else{
        int w1 = -1;
        int w2 = -1;

        for(int i = 0; i < words.size(); i++){
            if(words[i] == word1){
                w1 = i;
            }
            if(words[i] == word2){
                w2 = i;
            }
            if(w1 != -1 && w2 != -1){
                minDis = min(minDis, abs(w2-w1));
            }
        }
    }
    return minDis;
}

int main(){
    int n;
    cin >> n;
    vector<string>words(n);

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        words.push_back(s);
    }

    string word1;
    cin >> word1;
    string word2;
    cin >> word2;

    cout << min_distance(words, word1, word2);
}