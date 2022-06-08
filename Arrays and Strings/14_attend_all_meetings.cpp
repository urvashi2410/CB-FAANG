#include <bits/stdc++.h>
using namespace std;

bool canAttendMeetings(vector<vector<int>>&intervals){
    sort(intervals.begin(), intervals.end());
    int i = 1;
    while(i < intervals.size()){
        if(intervals[i-1][1] > intervals[i][0]){
            return false;
        }
        i++;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>>intervals;
    for(int i = 0; i < n; i++){
        int s;
        cin >> s;
        int e;
        cin >> e;
        vector<int>temp;
        temp.push_back(s);
        temp.push_back(e);
        intervals.push_back(temp);
    }

    if(canAttendMeetings(intervals)){
        cout << "Yes! I can attend all the meetings";
    }
    else{
        cout << "No! I can't :( ";
    }
}