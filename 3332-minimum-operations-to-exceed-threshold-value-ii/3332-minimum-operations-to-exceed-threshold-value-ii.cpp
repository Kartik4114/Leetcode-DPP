class Solution {
public:
    int minOperations(vector<int>& nums, int k) {         
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        
        for(auto num:nums){
            pq.push(num);
        }
        
        int c=0;
        while( pq.size()>=2 && pq.top()<k){
            long long top1=pq.top();
            pq.pop();
            long long top2=pq.top();
            pq.pop();
            
            long long ans=min(top1,top2)*2+max(top1,top2);
            
            pq.push(ans);
            
            c++;
            
        }
        
        return c;
    }
};