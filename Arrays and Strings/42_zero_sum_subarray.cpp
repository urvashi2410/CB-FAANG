class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        unordered_map<ll,ll>m;
        m.insert(make_pair(0,1));
        
        vector<ll>prefixSum(n);
        prefixSum[0] = arr[0];
        
        if(m.find(prefixSum[0]) != m.end()){
            m.insert(make_pair(prefixSum[0], m[prefixSum[0]]+1));
        }
        else{
            m.insert(make_pair(prefixSum[0], 1));
        }
        
        for(ll i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1] + arr[i];
            if(m.find(prefixSum[i]) != m.end()){
                m.insert(make_pair(prefixSum[i], m[prefixSum[i]] + 1));
            }
            else{
                m.insert(make_pair(prefixSum[i], 1));
            }
        }
        
        ll count = 0;
        // for(auto i = m.begin(); i != m.end(); i++){
        //     ll freq = i->second;
        //     if(freq > 1){
        //         count += freq*(freq-1)/2;
        //     }
        // }
        for(auto i : m){
            ll freq = i.second;
            if(freq > 1){
                count += freq*(freq-1)/2;
            }
        }
        return count;
    }
};