class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (auto &num : nums) {
            mp[num]++;
        }

      priority_queue<pair<int,int>> pq;

       for(auto &it:mp){

            int num=it.first;
            int freq=it.second;
            
            pq.push({freq,num});
        }

        vector<int> ans;

        while(!pq.empty() && k>0){

            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};
