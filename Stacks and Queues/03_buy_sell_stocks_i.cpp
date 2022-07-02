// solution 1 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int>s;
        int maxProfit = 0;
        int n = prices.size();
        if(n == 0){
            return 0;
        }
        
        s.push(prices[0]);
        int i = 1;
        while(i < n){
            if(prices[i] < s.top()){
                s.push(prices[i]);
            }
            else{
                int p = prices[i] - s.top();
                maxProfit = max(maxProfit, p);
            }
            i++;
        }
        return maxProfit;
    }
};

// solution 2 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int i = 0; i < n; i++){
            minPrice = min(prices[i], minPrice);
            maxProfit = max(prices[i] - minPrice, maxProfit);
        }
        return maxProfit;
    }
};