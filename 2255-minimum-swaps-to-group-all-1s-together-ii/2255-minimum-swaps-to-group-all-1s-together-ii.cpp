class Solution {
public:
    int a1(vector<int> &nums){

        int n=nums.size();
        vector<int> temp(2*n);

        for(int i=0;i<2*n;i++){
            temp[i]=nums[i%n];
        }

        int cntOne=0;
        for(auto num:nums){
            if(num==1) cntOne++;
        }

        int windowSize=cntOne;

        int i=0;
        int j=0;
        int maxCurrOneCount=0;
        int currCountOne=0;
        while(i<2*n){

            while(j<2*n && j-i+1<=windowSize){
                if(temp[j]==1) currCountOne++;
                j++;
            }
            maxCurrOneCount=max(maxCurrOneCount,currCountOne);
            if(temp[i]==1) currCountOne--;
            i++;
        }

        return cntOne-maxCurrOneCount;

    }
    int minSwaps(vector<int>& nums) {
        
        // approach 1:- 
        // T.C:- O(n) , S.C :- O(2*n)
        return a1(nums);
    }
};