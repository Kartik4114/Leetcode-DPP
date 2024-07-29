class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n=s.size();

        vector<int> prefixSum(n,0);

        for(int i=0;i<n;i++){
            if(s[i]=='1')
                prefixSum[i]=1;
        }

        for(int i=1;i<n;i++){
            prefixSum[i]+=prefixSum[i-1];
        }

        int result=0;
        for(int i=0;i<n;i++){

            int zeros=0;int ones=0;
            for(int j=i;j<n;j++){

                ones=prefixSum[j];
                if(i!=0){
                    ones-=prefixSum[i-1];
                }

                int zeros=j-i+1-ones;

                if(zeros*zeros>ones){
                    int diff=zeros*zeros-ones;
                    j+=(diff-1);
                }

                else {
                    result++;

                    if(ones>zeros*zeros){
                        int extraOnes=sqrt(ones)-zeros;
                        int nextj=j+extraOnes;

                        if(nextj>=n){
                            result+=(n-j-1);
                        } else result+=extraOnes;

                        j=nextj;
                    }
                }

            }
        }
        return result;
    }
};