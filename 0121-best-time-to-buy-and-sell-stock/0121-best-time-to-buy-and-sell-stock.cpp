class Solution {
public:
    int a1(vector<int>& prices){

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

    int a2(vector<int>& prices){

        int n=prices.size();
        int maxProfit=0;
        int mini=prices[0];

        for(int i=1;i<n;i++){

            int cost=prices[i]-mini;
            maxProfit=max(maxProfit,cost);
            mini=min(mini,prices[i]);

        }
        return maxProfit;
    }
    int maxProfit(vector<int>& prices) {
        
        // APPROACH 1:- MY APPROACH
        // return a1(prices);

        // APPROACH 2:-
        return a2(prices);
        
    }
};