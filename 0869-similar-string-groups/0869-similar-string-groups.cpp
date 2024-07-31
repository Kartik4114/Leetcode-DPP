class Solution {
public:
    bool isSimilar(string str1,string str2){
        int diffCnt=0;
        int n=str1.size();
        for(int k=0;k<n;k++){
            if(str1[k]!=str2[k]) diffCnt++;
        }

        return diffCnt<=2;
    }
    void DFS(unordered_map<int,vector<int>> &adj,vector<bool> &visited,int u){
        visited[u]=true;

        for(auto &v:adj[u]){
            if(!visited[v]){
                DFS(adj,visited,v);
            }
        }
    }
    int a1(vector<string> &strs){

        unordered_map<int,vector<int>> adj;

        int m=strs.size();
        for(int i=0;i<m;i++){

            for(int j=i+1;j<m;j++){

                if(isSimilar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(m,false);

        int cnt=0;
        for(int i=0;i<m;i++){
            if(!visited[i]){
                DFS(adj,visited,i);
                cnt++;
            }
        }
        return cnt;
    }

    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){

        int parent_x=find(x);
        int parent_y=find(y);

        if(parent_x==parent_y) return;

        if(rank[parent_x]<rank[parent_y]){
            parent[parent_x]=parent_y;
        } else if(rank[parent_y]<rank[parent_x]){
            parent[parent_y]=parent_x;
        } else {
            parent[parent_y]=parent_x;
            rank[parent_x]++;
        }
    }

    int a2(vector<string> &strs){
        
        
        int n=strs.size();
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int groupCount=n;

        unordered_map<int,vector<int>> adj;

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                if(isSimilar(strs[i],strs[j]) && find(i)!=find(j)){
                    Union(i,j);
                    groupCount--;
                }
            }
        }
        return groupCount;
    }
    int numSimilarGroups(vector<string>& strs) {
        
        // APPROACH 1:- USING DFS AND BFS
        // SIMILARLY WE CAN CHECK FOR BFS
        // return a1(strs);

        // APPROACH 2:- USING DSU
        return a2(strs);
    }
};