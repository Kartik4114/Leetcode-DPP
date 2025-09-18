class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();

        int minEl=prices[0];

        int maxi=0;

        for(int i=1;i<n;i++){

            int curr=prices[i]-minEl;
            maxi=max(maxi,curr);
            minEl=min(minEl,prices[i]);
        }

        return maxi;
    }
};