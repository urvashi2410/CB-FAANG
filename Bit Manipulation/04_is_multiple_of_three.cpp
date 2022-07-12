#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    int odd_count = 0;
    int even_count = 0;
    for(int i = 0; i < str.size(); i++){
        if(i % 2 != 0 && str[i] == '1'){
            odd_count++;
        }
        if(i % 2 == 0 && str[i] == '1'){
            even_count++;
        }
    }

    if((2*(odd_count) + even_count)%3 == 0){
        cout << "1\n";
    }
    else{
        cout << "0\n";
    }
}