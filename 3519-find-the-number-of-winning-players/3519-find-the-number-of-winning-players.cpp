class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp;
            
            for(int j=0;j<pick.size();j++){
                if(pick[j][0]==i){
                    int color=pick[j][1];
                    mp[color]++;
                    if(mp[color]>i){
                        ans++;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};