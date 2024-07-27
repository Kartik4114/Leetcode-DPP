class Solution {
public:
    void floydWarshall(vector<vector<long long>> &adj,vector<char> &original,vector<char> &changed,vector<int> &cost){
        
        for(int i=0;i<original.size();i++){

            int s=original[i]-'a';
            int t=changed[i]-'a';

            adj[s][t]=min(adj[s][t],(long long)cost[i]);
        }

        for(int via=0;via<26;via++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){

                    adj[i][j]=min(adj[i][j],adj[i][via]+adj[via][j]);
                }
            }
        }
    }
    long long a1(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost){

        vector<vector<long long>> adj(26,vector<long long>(26,INT_MAX));

        floydWarshall(adj,original,changed,cost);

        long long ans=0;
        for(int i=0;i<source.length();i++){
            if(source[i]==target[i]) continue;

            if(adj[source[i]-'a'][target[i]-'a']==INT_MAX) return -1;

            ans+=adj[source[i]-'a'][target[i]-'a'];
        }

        return ans;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        // APPROACH 1:- USING FLOYD WARSHALL ALGORITHM
        return a1(source,target,original,changed,cost);
    }
};