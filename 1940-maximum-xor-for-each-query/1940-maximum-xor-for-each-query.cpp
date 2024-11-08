class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        int n=nums.size();
        
        vector<int> xorArr(n);

        xorArr[0]=nums[0];
        for(int i=1;i<n;i++){
            xorArr[i]=(xorArr[i-1]^nums[i]);
        }

        for(int i=0;i<n;i++){
         cout<<xorArr[i]<<" ";
        }

        cout<<endl;
        vector<int> temp=xorArr;

        for(int i=0;i<n;i++){

            for(int bits=0;bits<maximumBit;bits++){

                if((xorArr[i] & (1<<bits))==0){
                    xorArr[i]= (xorArr[i] ^ (1<<bits));
                }
            }

            cout<<xorArr[i]<<" ";
        }

        vector<int> result(n);
        for(int i=0;i<n;i++){
            result[i]=temp[i] ^ xorArr[i];
        }

        reverse(result.begin(),result.end());
        return result;


    }
};