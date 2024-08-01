class Solution {
public:
    typedef pair<string,double> p;

    double dfs(unordered_map<string,vector<p>> &adj,unordered_set<string> &visited,string s,string d){
        
        visited.insert(s);
        if(s==d) return 1.0;

        double ans=0;
        for(auto &node:adj[s]){

            string v=node.first;
            double val=node.second;

            if(visited.find(v)==visited.end()){
                ans+=(val*dfs(adj,visited,v,d));
            }
        }
        return ans;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string,vector<p>> adj;

        int i=0;
        for(auto &eq:equations){
            string u=eq[0];
            string v=eq[1];
            double val=values[i];
            i++;

            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});
        }

        int n=queries.size();
        vector<double> result;
        for(auto &query:queries){
        unordered_set<string> visited;

            string src=query[0];
            string dest=query[1];

            if(adj.find(src)==adj.end()){
                result.push_back(-1*1.0);
                continue;
            }

            double ans=dfs(adj,visited,src,dest);
            if(ans==0) result.push_back(-1*1.0);
            else result.push_back(ans*1.0);
        }
        return result;
    }
};