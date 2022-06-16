#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        int m = version2.size();
        int i = 0;
        int j = 0;
        
        while(i < n || j < m){
            int num1 = 0;
            int num2 = 0;
            while(i < n && version1[i] != '.'){
                int num = version1[i] - '0';
                num1 = num1*10 + num;
                i++;
            }
            while(j < m && version2[j] != '.'){
                int num = version2[j] - '0';
                num2 = num2*10 + num;
                j++;
            }
            if(num1 > num2){
                return 1;
            }
            else if(num1 < num2){
                return -1;
            }
            else{
                i++;
                j++;
            }
        }
        return 0;
    }
};