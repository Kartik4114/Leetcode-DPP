class Solution {
public:
    int solve(string &s,unordered_set<string> &st,int idx,vector<int> &dp){
        int n=s.size();
        if(idx>=n) return 0;

        if(dp[idx]!=-1) return dp[idx];

        int minExtra=INT_MAX;
        string currString="";

        for(int i=idx;i<n;i++){
            currString+=s[i];
            int currLen=0;

            if(st.find(currString)==st.end()){
                currLen=currString.size();
            }

            int remainExtra=solve(s,st,i+1,dp);
            int totalExtra=(currLen+remainExtra);

            minExtra=min(minExtra,totalExtra);
        }

        return dp[idx]=minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        
        int n=s.size();
        unordered_set<string> st(dictionary.begin(),dictionary.end());
        vector<int> dp(n+1,-1);
        return solve(s,st,0,dp);
    }
};