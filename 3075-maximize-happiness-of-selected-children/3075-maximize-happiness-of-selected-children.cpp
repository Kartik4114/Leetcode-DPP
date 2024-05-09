class Solution {
public:
    long long a1(vector<int>& happiness, int k) {

        priority_queue<int> pq;
        for(auto &hap:happiness){
            pq.push(hap);
        }

        int hap_dec=0;
        long long hap_cnt=0;

        while(!pq.empty() && hap_dec<k){
            int top=pq.top();
            pq.pop();

            if(top-hap_dec>0)
            hap_cnt+=(top-hap_dec);

            hap_dec++;
        }
        return hap_cnt;
    }

    long long a2(vector<int>& happiness, int k) {
        
        int n=happiness.size();
        sort(happiness.begin(),happiness.end(),greater<int>());

        int dec=0;
        long long hap_cnt=0;
        int i=0;
        while(i<n && dec<k){
            
            int val=happiness[i]-dec;
            
            hap_cnt+=max(0,val);
            i++;
            dec++;
        }
        return hap_cnt;

    }
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        // APPROACH 1:- USING MAX HEAP
        // T.C :- O(NLOGN) , S.C:- O(N)
            return a1(happiness,k);
        
        // APPROACH 2:- USING SORTING
        // T.C :- O(NLOGN) , S.C:- O(1)
            return a2(happiness,k);
       
    }
};