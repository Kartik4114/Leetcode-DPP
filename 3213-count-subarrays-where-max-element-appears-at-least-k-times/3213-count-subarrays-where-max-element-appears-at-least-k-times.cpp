class Solution {
public:
    long long a1(vector<int>& nums, int k){
        int n=nums.size();
        // shortcut to find maximum element
        int maxE=*max_element(nums.begin(),nums.end());

        int i=0;
        int j=0;
        long long result=0;
        int countMax=0;

        while(j<n){
            if(nums[j]==maxE){
                countMax++;
            }
            
            while(countMax>=k){
                
                result+=n-j;
                if(nums[i]==maxE){
                    countMax--;
                }
                i++;
            }
            j++;
        }

        return result;
    }
    long long a2(vector<int>& nums, int k){
        int n=nums.size();

        int maxE=*max_element(nums.begin(),nums.end());
        long long result=0;
        vector<int> maxindices;

        for(int i=0;i<n;i++){
            if(nums[i]==maxE){
                maxindices.push_back(i);
            }

            int size=maxindices.size();
            if(size>=k){
            int last_i=maxindices[size-k];
            result+=last_i+1;
            }
        }


        return result;
        
    }
    long long countSubarrays(vector<int>& nums, int k) {
        // APPROACH 1:- USING SLIDING WINDOW TECHNIQUE 
                    // time :- O(n) , space :- O(1)
            return a1(nums,k);
        
        // APPROACH 2:- TRICKY APPROACH 
            // time :- O(n) , space :- O(n)
            return a2(nums,k);
    }
};