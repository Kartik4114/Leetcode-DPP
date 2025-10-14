class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
       
        
        int n = nums.size();
        int i = 0;

        
        while (i  < n-2*k+1) {
            bool fInc = true, sInc = true;

            
            int j = i;
            while (j < i + k - 1) {
                
                if (nums[j] >= nums[j + 1]) {
                    
                    fInc = false;
                    break;
                }
                j++;
            }


            if (fInc==true) {
                
                int p=i+k;
               // j = i + k;
                
                while (p < i + 2 * k - 1) {
                    if (nums[p] >= nums[p + 1]) {
                        sInc = false;
                        break;
                    }
                    p++;
                }
                j=p;

                if (sInc==true) return true;
            }

            i++;
        }

        return false;
    }
};
