class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int n=customers.size();

        int sumNotGrumpy=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) sumNotGrumpy+=customers[i];
        }
        // cout<<  sumNotGrumpy<<endl;

        int j;
        int maxSumGrumpy=0;
        int currSumGrumpy=0;

        for(j=0;j<minutes;j++){
            if(grumpy[j]==1) currSumGrumpy+=customers[j];
        }

        // while(j<minutes){
        //     if(grumpy[j]==1) currSumGrumpy+=customers[j];
        //     j++;
        // }
        j--;

        maxSumGrumpy=currSumGrumpy;

        int i=0;
        cout<<i<<" "<<j<<endl;
        while(i<n && j+1<n){

            j++;
            if(grumpy[j]==1){
                currSumGrumpy+=customers[j];
            }

            if(grumpy[i]==1){
                currSumGrumpy-=customers[i];
            }
            i++;
            cout<<i<<" "<<j<<" "<<currSumGrumpy<<endl;
            maxSumGrumpy=max(maxSumGrumpy,currSumGrumpy);
            
        }

        return sumNotGrumpy + maxSumGrumpy;

    }
};