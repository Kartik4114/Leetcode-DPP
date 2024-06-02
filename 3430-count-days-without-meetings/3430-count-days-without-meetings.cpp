class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
//         unordered_map<int,int> mp;
//         int n = meetings.size();
        
//         for(int i = 0; i < n; i++) {
            
//             for(int j = meetings[i][0]; j <= meetings[i][1]; j++) {
//                 if(mp.find(j)==mp.end())
//                     mp[j]++;
//             }
//         }
        
//         int cnt = 0;
//         for(int i = 1; i <= days; i++) {
//             if(mp.find(i) == mp.end()) cnt++;
//         }
//         return cnt;
        
        if (meetings.empty()) return days;

    sort(meetings.begin(), meetings.end());

    // Vector to hold merged intervals
    vector<pair<int, int>> inter;
    int currStart = meetings[0][0];
    int currEnd = meetings[0][1];

    for (int i = 1; i < meetings.size(); ++i) {
        if (meetings[i][0] <= currEnd + 1) {
            currEnd = max(currEnd, meetings[i][1]);
        } else {
            inter.push_back({currStart, currEnd});
            currStart = meetings[i][0];
            currEnd = meetings[i][1];
        }
    }
    inter.push_back({currStart, currEnd});

    
    int f_days = 0;

    if (inter[0].first > 1) {
        f_days += inter[0].first - 1;
    }

    for (int i = 1; i < inter.size(); ++i) {
        f_days += inter[i].first - inter[i - 1].second - 1;
    }

    if (inter.back().second < days) {
        f_days += days - inter.back().second;
    }

    return f_days;
    }
};
