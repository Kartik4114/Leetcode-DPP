class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int result=0;

        int curr=prices[0];
        for(int i=1;i<n;i++){
            
            if(prices[i]>curr){
                result=max(result,prices[i]-curr);
            } else {
                curr=prices[i];
            }
        }
        return result;
        
    }
};