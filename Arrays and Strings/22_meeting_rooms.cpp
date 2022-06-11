#include<bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals){
    vector<int>start;
    vector<int>ending;

    for(int i = 0; i < intervals.size(); i++){
        start.push_back(intervals[i][0]);
        ending.push_back(intervals[i][1]);
    }

    sort(start.begin(), start.end());
    sort(ending.begin(), ending.end());

    int i = 1, j = 0, count = 1;
    int ans = 1;

    while(i < start.size() && j < ending.size()){
        if(start[i] < ending[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        ans = max(ans, count);
    }
    return ans;
}

int main(){
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    cout << minMeetingRooms(intervals);
    return 0;
}