class Solution {
public:
    vector<int> a1(vector<int>& nums, int maximumBit){
        int n=nums.size();
        
        vector<int> xorArr(n);

        xorArr[0]=nums[0];
        for(int i=1;i<n;i++){
            xorArr[i]=(xorArr[i-1]^nums[i]);
        }

        vector<int> temp=xorArr;

        for(int i=0;i<n;i++){

            for(int bits=0;bits<maximumBit;bits++){

                if((xorArr[i] & (1<<bits))==0){
                    xorArr[i]= (xorArr[i] ^ (1<<bits));
                }
            }
        }

        vector<int> result(n);
        for(int i=0;i<n;i++){
            result[i]=temp[i] ^ xorArr[i];
        }

        reverse(result.begin(),result.end());
        return result;
    }
    vector<int> a2(vector<int>& nums, int maximumBit){
        
        int n=nums.size();
        vector<int> result(n);

        // Find the total XOR
        int XOR = 0;
        for(int i=0;i<n;i++){
            XOR ^=nums[i];
        }

        // To find flip , firstly finding the mask of all bits set to 1
        int mask= (1<<maximumBit) -1;

        for(int i=0;i<n;i++){
            int k=XOR ^ mask;

            result[i]=k;
            XOR = XOR ^ nums[n-i-1];
        }
        return result;
    }
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        // APPROACH 1:- MY APPROACH 
        // T.C :- O(N) , S.C :- O(N)
        // return a1(nums,maximumBit);

        // APPROACH 2:- JUST LITTLE SIMPLE APPROACH (Actual approach)
        // NICEEE APPROACH
        // T.C :- O(N) , S.C :- O(N)
        return a2(nums,maximumBit);

    }
};