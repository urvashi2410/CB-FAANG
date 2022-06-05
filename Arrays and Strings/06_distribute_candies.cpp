class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_map<int, int>m;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(m.find(candyType[i]) == m.end()){
                m.insert({candyType[i], 1});
                count++;
            }
            else{
                m[candyType[i]]++;
            }
        }
        int ans = count<n/2?count:n/2;
        return ans;
    }
};

// second solution 

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int noOfCandies = candyType.size();
        set<int>s;
        for(int i : candyType){
            s.insert(i);
        }
        int noOfVarieties = s.size();
        return min(noOfCandies/2, noOfVarieties);
    }
};