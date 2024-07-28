class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n=s.length();
        int ans=0;

        vector<int> prefixSumOne(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                prefixSumOne[i]=1;
            }
        }

        // prefix sum of one
        for(int i=1;i<n;i++){
            prefixSumOne[i]+=prefixSumOne[i-1];
        }

        for(int i=0;i<n;i++){
            int zeros=0,ones=0;

            for(int j=i;j<n;j++){
                ones=prefixSumOne[j];
                if(i!=0) ones-=prefixSumOne[i-1];
                zeros=j-i+1-ones;

                // if condition false
                if(zeros*zeros>ones){
                    int diff=zeros*zeros-ones;
                    j+=(diff-1); // -1 is bec in for loop we have already j++
                }

                // if condition is true
                else {
                    ans++;

                    if(ones>zeros*zeros){
                        int diff=sqrt(ones)-zeros;
                        int nextj=j+diff;

                        if(nextj>=n){
                            ans+=(n-j-1);
                        } else ans+=diff;

                        j=nextj;
                    }
                }
            }
        }

        return ans;
    }
};