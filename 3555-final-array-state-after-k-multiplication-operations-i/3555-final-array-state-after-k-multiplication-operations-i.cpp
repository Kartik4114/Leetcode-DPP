class Solution {
public:
    typedef pair<int,int> P;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        int n = nums.size();
        priority_queue<P, vector<P>, greater<P>> pq;
        
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        
        while (k > 0) {
            auto top = pq.top();
            pq.pop();
            
            top.first *= multiplier;
            pq.push(top);
            
            k--;  // Decrement k to avoid infinite loop
        }
        
        vector<int> result(n);
        while (!pq.empty()) {
            int idx=pq.top().second;
            result[idx]=pq.top().first;
            pq.pop();
        }
        return result;
    }
};
