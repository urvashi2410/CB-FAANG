class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1){
            return 0;
        }
        if(n == INT_MAX){
            return 32;
        }
        if(n % 2 == 0){
            return integerReplacement(n/2) + 1;
        }
        if(n == 3 || n % 4 == 1){
            return integerReplacement(n-1) + 1;
        }
        return integerReplacement(n+1) + 1;
    }
};