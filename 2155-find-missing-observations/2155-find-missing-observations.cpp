class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int m=rolls.size();

        int sumOfM=0;
        for(auto &roll :rolls){
            sumOfM+=roll;
        }

        int sumOfN=(n+m)*mean -sumOfM;
        int num=sumOfN/n;

        if(sumOfN > n*6 || sumOfN<=0) return {};
        if(sumOfN<n) return {};

        vector<int> result(n,num);

        int currSum=n*num;
        int diffSum=(sumOfN-currSum);

        for(int i=0;i<n;i++){

            if(result[i]+diffSum>6){
                diffSum-=(6-result[i]);
                result[i]=6;
            } else {
                result[i]+=diffSum;
                diffSum=0;
            }
            if(diffSum==0) break;
        }
        return result;
        
    }
};