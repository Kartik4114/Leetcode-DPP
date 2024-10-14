class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        long long score=0;

        priority_queue<int> pq;

        for(auto &num:nums) pq.push(num);

        while(k>0){

            long long top=pq.top();
            pq.pop();

            score+=top;
            pq.push(ceil(top/(3*1.0)));

            k--;
        }

        return score;
    }
};