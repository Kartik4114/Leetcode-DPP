class Solution {
public:
    int a1(vector<int> &nums){

        int n=nums.size();
        int ramp=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                if(nums[i]<=nums[j]){
                    ramp=max(ramp,j-i);
                }
            }
        }

        return ramp;
    }

    int a2(vector<int> &nums){

        int n=nums.size();

        int ramp=0;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>i;j--){

                if(nums[j]>=nums[i]){
                    ramp=max(ramp,j-i);
                    break;
                }
            }
        }

        return ramp;
    }

    int a3(vector<int> &nums){

        int n=nums.size();

        vector<int> rightMax(n);

        rightMax[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],nums[i]);
        }

        int ramp=0;
        int j=0;
        int i=0;
        while(j<n){

            while(j<n && nums[i]<=rightMax[j]){
                j++;
            }

            ramp=max(ramp,j-i-1);
            i++;
        }

        return ramp;
    }
    int maxWidthRamp(vector<int>& nums) {
        
        // APPROACH 1:- USING BRUTE FORCE 
        // T.C :- O(n^2) , S.C :- O(1)
        // return a1(nums);

         // APPROACH 2:- BETTER APPROACH THAN APPROACH 1 (LITTLE OPTIMISED)
        // T.C :- O(n^2) , S.C :- O(1)
        // return a2(nums);

        // APPROACH 3:- MOST OPTISIED APPROACH 
        // T.C :- O(n) , S.C :- O(n)
        return a3(nums);

    }
};