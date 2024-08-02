class Solution {
public:
    int a1(vector<int> &nums){

        int n=nums.size();
        vector<int> temp(2*n);

        for(int i=0;i<2*n;i++){
            temp[i]=nums[i%n];
        }

        int totalOnes=0;
        for(auto num:nums){
            totalOnes+=num;
        }

        int i=0;
        int j=0;

        int currOnes=0;
        int maxCount=0;

        while(j<2*n){
            if(temp[j]==1) currOnes++;

            if(j-i+1>totalOnes){
                currOnes-=temp[i];
                i++;
            }

            maxCount=max(maxCount,currOnes);
            j++;
        }
        return totalOnes-maxCount;

    }

        int a2(vector<int> &nums){

        int n=nums.size();
    
        int totalOnes=0;
        for(auto num:nums){
            totalOnes+=num;
        }

        int i=0;
        int j=0;

        int currOnes=0;
        int maxCount=0;

        while(j<2*n){
            if(nums[j%n]==1) currOnes++;

            if(j-i+1>totalOnes){
                currOnes-=nums[i%n];
                i++;
            }

            maxCount=max(maxCount,currOnes);
            j++;
        }
        return totalOnes-maxCount;

    }
    int minSwaps(vector<int>& nums) {
        
        // Approach 1:- Using Sliding Window
        // T.C:- O(n) , S.C :- O(2*n)
        // return a1(nums);

        // Approach 2:- Using Sliding Window
        // T.C:- O(n) , S.C :- O(1)
        return a2(nums);
    }
};