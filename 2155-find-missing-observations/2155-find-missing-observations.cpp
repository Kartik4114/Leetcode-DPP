class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int m=rolls.size();

        int sumOfM=0;
        for(auto &roll :rolls){
            sumOfM+=roll;
        }

        int sumOfN=(n+m)*mean -sumOfM;

        if(sumOfN > n*6 || sumOfN<=0) return {};

        int num=sumOfN/n;
        cout<<sumOfM<<" ";
        cout<<sumOfN<<" "<<num<<endl;

        if(sumOfN<n) return {};
        // if(num==0) num=1;
        vector<int> result(n,num);

        int currSum=n*num;

        int diffSum=(sumOfN-currSum);
        cout<<currSum<<" "<<diffSum<<endl;

        // for(int i=0;i<n;i++) cout<<result[i]<<" ";
        cout<<endl;
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