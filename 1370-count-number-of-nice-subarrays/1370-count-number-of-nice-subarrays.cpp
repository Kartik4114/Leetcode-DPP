class Solution {
public:
    int a1(vector<int> &nums,int k){
        unordered_map<int,int> mp;

        int result=0;
        int oddCount=0;
        mp[oddCount]++;
        
        for(auto num:nums){

            if(num%2==1){
                oddCount++;
            }

            if(mp.count(oddCount-k)){
                result+=mp[oddCount-k];
            }
            mp[oddCount]++;

        }
        return result;
    }
    
    int a2(vector<int> &nums,int k){
        
        int n=nums.size();
        int oddCount=0;
        int prevCount=0;
        int result=0;

        int i=0,j=0;
        while(j<n){

            if(nums[j]%2==1){
                oddCount++;
                prevCount=0;
            }

            while(oddCount==k){
                if(nums[i]%2==1){
                    oddCount--;
                }
                prevCount++;
                i++;
            }

            result+=prevCount;
            j++;
        }

        return result;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        // APPROACH 1:- using map and storing whether we got the result in past or not
        // return a1(nums,k);

        // APPROACH 2:- USING SLIDING WINDOW TECHNIQUE (IMP. APPROACH)
        return a2(nums,k);
    }
};