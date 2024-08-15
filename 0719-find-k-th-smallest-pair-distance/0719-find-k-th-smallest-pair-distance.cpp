class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        
        int n=nums.size();
        int maxElement=*max_element(nums.begin(),nums.end());

        vector<int> vec(maxElement+1,0);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                int diff=abs(nums[j]-nums[i]);
                vec[diff]++;
            }
        }

        for(int i=0;i<vec.size();i++){

            k-=vec[i];
            if(k<=0) return i;
        }
        return -1;
    }
};