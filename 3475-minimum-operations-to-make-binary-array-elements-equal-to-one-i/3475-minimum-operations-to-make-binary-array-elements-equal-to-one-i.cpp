class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n=nums.size();
        int i=0;
        int j=2;
        int result=0;
        
        while(i<n && j<n){
            
            if(nums[i]==0){
                int k=i;
                while(k<=j){
                    if(nums[k]==1) nums[k]=0;
                    else nums[k]=1;
                    k++;
                    
                }
                result++;
            }
            
            i++;
            j++;
            
        }
        
        int cnt=0;
        
        for(auto num:nums){
            if(num==1) cnt++;
        }
        
        if(cnt!=nums.size()) return -1;
        
        return result;
        
    }
};