class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int n=prices.size();

        vector<int> result;

        for(int i=0;i<n;i++){

            int currPrice=prices[i];

            for(int j=i+1;j<n;j++){
                if(prices[j]<=prices[i]){
                    currPrice-=prices[j];
                    break;
                }
            }
            result.push_back(currPrice);
        }

        return result;
    }
};