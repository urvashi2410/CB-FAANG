// solution 1 

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        return !(n&(n-1));
    }
};

// solution 2 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        // count the setbits 
        int count = 0;
        while(n){
            if(n&1){
                count++;
            }
            n>>=1;
        }
        if(count == 1){
            return true;
        }
        else{
            return false;
        }
    }
};