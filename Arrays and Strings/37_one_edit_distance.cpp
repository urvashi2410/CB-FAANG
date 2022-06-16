#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isOneEditDistance(string s, string t){
        string s1 = s.size() <= t.size()? s:t;
        string s2 = s.size() > t.size()? s:t;
        int i = 0, j = 0, count = 0;
        if(s1.size() < s2.size()){
            while(s1.size() && j < s2.size()){
                if(s1[i] == s2[j]){
                    i++;
                    j++;
                    count++;
                }
                else{
                    j++;
                }
            }
        }
        else{
            while(i < s1.size() && j < s2.size()){
                if(s1[i] == s2[j]){
                    count++;
                }
                i++;
                j++;
            }
        }
        if(s2.size()-1 == count){
            return true;
        }
        else{
            return false;
        }
    }
};