class Solution {
public:
    vector<int> isPrimes;

    void seive(){
        isPrimes.resize(1000,1);

        isPrimes[0]=0;
        isPrimes[1]=0;

        for(int i=2;i<1000;i++){
            if(isPrimes[i]){

                for(int j=i*i;j<1000;j+=i){
                    isPrimes[j]=0;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        
        int n=nums.size();

        seive();

        for(int i=n-2;i>=0;i--){

            if(nums[i]<nums[i+1]) continue;

            for(int p=2;p<nums[i];p++){
                if(!isPrimes[p]) continue;

                if(nums[i]-p < nums[i+1]){
                    nums[i]-=p;
                    break;
                }
            }

            if(nums[i]>=nums[i+1]) return false;
        }
        return true;
    }
};