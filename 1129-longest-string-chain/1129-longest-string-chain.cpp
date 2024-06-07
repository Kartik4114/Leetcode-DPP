class Solution {
public:
    static bool myFunction(string &prev,string &curr){
        return prev.size()<curr.size();
    }

    int memo[1001][1001];
    
    bool isPred(string &curr_idx,string &prev_idx){
        
        int m=prev_idx.size();
        int n=curr_idx.size();

        if(n-m!=1) return false;

        int i=0,j=0;
        while(i<m && j<n){
            if(prev_idx[i]==curr_idx[j]) i++;

            j++;
        }

        return i==m;
    }
    int a1(vector<string> &words,int idx, int prev_idx){
        int n=words.size();

        if(idx>=n) return 0;
        if(prev_idx !=-1 && memo[idx][prev_idx]!=-1) return memo[idx][prev_idx];

        int skip=a1(words,idx+1,prev_idx);

        int take=0;
        if(prev_idx==-1 || isPred(words[idx],words[prev_idx])){
            take=1+a1(words,idx+1,idx);
        }

        if(prev_idx==-1) return max(skip,take);
        return memo[idx][prev_idx]=max(skip,take);
    }

    int a2(vector<string>& words){
        int n=words.size();

        vector<int> dp(n,1);

        int maxLIS=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(isPred(words[i],words[j])){
                    dp[i]=max(dp[i],dp[j]+1);

                    maxLIS=max(maxLIS,dp[i]);

                }
            }
        }

        return maxLIS;
        
    }
    int longestStrChain(vector<string>& words) {

        // APPROACH 1:- USING RECURSION + MEMOIZATION
        sort(words.begin(),words.end(),myFunction);
        
        memset(memo,-1,sizeof(memo));
        // return a1(words,0,-1);

        // APPROACH 2:- USING DYNAMIC PROGRAMMING
        return a2(words);
    }
};