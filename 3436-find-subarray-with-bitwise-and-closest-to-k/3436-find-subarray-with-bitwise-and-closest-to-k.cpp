class Solution {
public:
    void updateFreq(int operation,int val,vector<int> &freq){
        int i=0;
        while(val>0){
            if(val&1){
                freq[i]+=operation;
            }
            val=val/2;
            i++;
        }
    }
    int minimumDifference(vector<int>& nums, int k) {
        

        // T.C :- O(n*32) , S.C :- O(n)
        int n=nums.size();

        vector<int> freq(32,0);
        int i=0;
        int j=0;
        int AND =nums[0];

        int result=INT_MAX;

        while(j<n){ // O(n)
            AND &=nums[j];

            // T.C of update is :- O(32)
            updateFreq(1,nums[j],freq); // including nums[j] to AND
            result=min(result,abs(k-AND));

            if(AND>k){
                j++;
                continue;
            } else if(AND<k){
                while(i<=j && AND <k){ 
                    updateFreq(-1,nums[i],freq);
                    i++;
                    AND=0;
                    for(int b=0;b<32;b++){
                        if(j-i+1==freq[b])
                        AND=(AND | 1<<b);
                    }

                    result=min(result,abs(k-AND));
                }
            } else return 0; // when k== AND
            j++;

        }

        return result;
    }
    
};