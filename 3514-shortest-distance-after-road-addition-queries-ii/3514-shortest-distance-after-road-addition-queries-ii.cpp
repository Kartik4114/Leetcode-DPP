class Solution {
public:
    void eraseMiddleNodes(set<int>& st,int l,int r){
        auto start=st.lower_bound(l);
        auto end=st.upper_bound(r);
        st.erase(start,end);
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
       set<int> s;
        for(int i=0;i<n;i++){
            s.insert(i);
        }

        vector<int> ans;
        for(auto &query:queries){
            int x=query[0];
            int y=query[1];
            eraseMiddleNodes(s,x+1,y-1);
            ans.push_back(s.size()-1);
        }
        return ans;
    }
};