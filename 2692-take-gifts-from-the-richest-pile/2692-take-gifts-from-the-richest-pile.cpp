class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        int n=gifts.size();

        priority_queue<int> pq;

        for(auto &gift:gifts) pq.push(gift);

        while(k--){

            int top=pq.top();
            pq.pop();

            int toLeft=floor(sqrt(top));
            pq.push(toLeft);
        }

        long long result=0;

        while(!pq.empty()){
            result+=pq.top();
            pq.pop();
        }
        return result;
    }
};