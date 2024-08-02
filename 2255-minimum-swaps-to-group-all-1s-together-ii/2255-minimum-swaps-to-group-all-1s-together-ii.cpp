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
    int minSwaps(vector<int>& nums) {
        
        // approach 1:- 
        // T.C:- O(n) , S.C :- O(2*n)
        return a1(nums);
    }
};