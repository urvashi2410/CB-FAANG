class Solution {
public:
    int update(int n){
        int s = 0;
        while(n > 0){
            int d = n%10;
            s = s + d*d;
            n /= 10;
        }
        return s;
    }
    
    bool check(map<int, bool>m, int n){
        if(n == 1){
            return true;
        }
        // reached an infinite loop of repeating the same numbers again and again
        if(m.find(n) != m.end()){
            return false;
        }
        m.insert(make_pair(n, true));
        n = update(n);
        return check(m, n);
    }
    
    bool isHappy(int n){
        map<int, bool>m;
        return check(m, n);
    }
};

// second solution 
class Solution {
public:
    int next(int n){
        int ans = 0;
        while(n){
            ans += pow(n%10, 2);
            n /= 10;
        }
        return ans;
    }
    
    bool isHappy(int n) {
        int slow = next(n);
        int fast = next(next(n));

        while(slow != fast){
            slow = next(slow);
            fast = next(next(fast));
        }

        if(slow == 1){
            return true;
        }
        return false;
    }
};