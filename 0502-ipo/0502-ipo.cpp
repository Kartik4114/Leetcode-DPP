class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
    //Using heap and greedily picking up projects
    //T.C : O(nlogn)
    //S.C : O(n)
        int n=profits.size();
        vector<pair<int,int>> v(n);

        for(int i=0;i<n;i++){
            v[i]={capital[i],profits[i]};
        }

        sort(v.begin(),v.end());

        priority_queue<int> pq;

        int i=0;
        while(k--){

            while( i<n && v[i].first<=w){
                pq.push(v[i].second);
                i++;
            }
            if(pq.empty()) break;

            w+=pq.top();
            pq.pop();
        }

        return w;
    }
};