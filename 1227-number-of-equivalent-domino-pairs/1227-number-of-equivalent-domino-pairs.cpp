class Solution {
public:
    int findPairs(map<pair<int,int>,int>& mp){

        long long cnt=0;

        for(auto &it:mp){

            long long pair=(long long)(it.second*(long long)(it.second-1))/2;

            cnt+=pair;
        }

        return cnt;
    }
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        int n=dominoes.size();
        map<pair<int,int>,int>mp;


        for(auto &domino:dominoes){

            int a=domino[0];
            int b=domino[1];

            auto pair=make_pair(a,b);
            auto rotatedPair=make_pair(b,a);

            if(mp.find(rotatedPair)!=mp.end()){
                mp[rotatedPair]++;
            } else {
                mp[pair]++;
            }

        }

        int cnt=findPairs(mp);

        return cnt;

    }
};