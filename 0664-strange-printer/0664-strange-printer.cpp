class Solution {
public:
    int memo[101][101];
    int solve(string &s,int l,int r){

        if(l>r) return 0;
        if(l==r) return 1;

        if(memo[l][r]!=-1) return memo[l][r];
        int i=l+1;
        while(i<=r && s[i]==s[l]) i++;

        int basic=1+solve(s,i,r);

        int result=INT_MAX;
        for(int j=i;j<=r;j++){

            if(s[j]==s[l]){
                
                int ans=solve(s,i,j-1)+solve(s,j,r);
                result=min(result,ans);
            }
        }

        return memo[l][r]= min(result,basic); 
    }
    int strangePrinter(string s) {
        int n=s.size();
        memset(memo,-1,sizeof(memo));
        return solve(s,0,n-1);
    }
};