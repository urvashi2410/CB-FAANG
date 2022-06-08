#include <bits/stdc++.h>
using namespace std;

int min_distance(vector<string>words, string word1, string word2){
    int w1 = -1;
    int w2 = -1;
    int mini = words.size();

    for(int i = 0; i < words.size(); i++){
        if(words[i] == word1){
            w1 = i;
        }
        if(words[i] == word2){
            w2 = i;
        }
        if(w1 != -1 && w2 != -1){
            mini = min(mini, abs(w2-w1));
        }
    }
    return mini;
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