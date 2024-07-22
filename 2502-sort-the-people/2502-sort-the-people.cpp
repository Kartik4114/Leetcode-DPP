class Solution {
public:
    typedef pair<int,string> pp;
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        int n=names.size();
        priority_queue<pp> pq;

        for(int i=0;i<n;i++){
            
            string name=names[i];
            int height=heights[i];

            pp combinedPair={height,name};
            pq.push(combinedPair);
        }


        vector<string> result;
        while(!pq.empty()){
            
            auto top=pq.top();
            pq.pop();

            result.push_back(top.second);
        }
        return result;
    }
};