class Solution {
public:
    int dp[301];
    bool solve(string s, unordered_set<string> &st,int i){
        if(i>=s.size()){
            return true;
        }

        if(dp[i]!=-1){
            return dp[i];
        }
        int j=i;
        string temp="";
        while(j<s.size()){
            temp+=s[j];

            if(st.find(temp)!=st.end()){
                if(solve(s,st,j+1)) return dp[i]=1;
            }
            j++;
        }
        
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> st;
        memset(dp,-1,sizeof(dp));

        for(auto s:wordDict){
            st.insert(s);
        }

        return solve(s,st,0);
    }
};